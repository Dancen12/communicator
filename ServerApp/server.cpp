#include "server.h"
#include "serverlogger.h"
#include "mainwindow.h"
#include <QMessageBox>

Server* Server:: server = nullptr;
std::list<ClientHandler *> Server:: clientHandlers;

Server::Server()
{

}

void Server::setMainWindowPtr(MainWindow* mw)
{
    mainWindow = mw;
}

Server* Server::getInstance()
{
    if(!server)
    {
        server = new Server;
    }
    return server;
}
void Server:: process()
{
    if(!isListening())
    {
        if(listen(QHostAddress::Any,PORT))
        {
            ServerLogger::getInstance()->makeLog(QString("server is listening at port %1").arg(PORT));
        }
        else
        {
            ServerLogger::getInstance()->makeLog("Cannot run server");
            exit(-1);
        }
    }
    else
    {
        QMessageBox::information(mainWindow,"Notification","Server is already listening");
    }


}

void Server:: stop()
{
    for(auto handler :clientHandlers)
    {
        delete handler;
    }
    if(server)
    {
        delete server;
        server = nullptr;
    }
    ServerLogger::getInstance()->makeLog("Server stopped");
}

Server::~Server()
{
    for(auto handler: clientHandlers)
    {
        delete handler;
    }
    mainWindow->setNumberOfClientsLabel(clientHandlers.size());
}

void Server:: deleteHandler(ClientHandler* handler)
{
    QString log = "Connection with client ip: " +handler->getSocket()->peerAddress().toString()+" port: " +QString::fromStdString(std::to_string(handler->getSocket()->peerPort())) + " finished";
    ServerLogger::getInstance()->makeLog(log);
    clientHandlers.remove(handler);
    delete handler;
    mainWindow->setNumberOfClientsLabel(clientHandlers.size());
}

void Server:: forwardMessage(int sender_id, int receiver_id,const std::string& date, const std::string& content)
{
    for(auto& handler : clientHandlers)
    {
        if(handler->userID==receiver_id)
        {
            handler->newMessageArrived(sender_id,receiver_id,date,content);
        }
    }
    std::string log  = "Message forwarded between id: " +std::to_string(sender_id)+" and "+std::to_string(receiver_id)+". Message: " + content;
    ServerLogger::getInstance()->makeLogOnlyToFile(QString::fromStdString(log));
}


void Server:: incomingConnection(qintptr socketDescriptor)
{

    QTcpSocket* socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    ClientHandler* handler = new ClientHandler(socket, this);
    connect(handler,&ClientHandler::finished,this,&Server::deleteHandler);
    connect(handler, QOverload<int, int, const std::string&, const std::string&>::of(&ClientHandler::sendMessage),
            this, &Server::forwardMessage);
    clientHandlers.push_back(handler);
    std::thread t(&ClientHandler::serveClient,handler);
    t.detach();
    QString log = "Client captured. IP: " + socket->peerAddress().toString() + " Port: " + QString::fromStdString(std::to_string(socket->peerPort()));
    ServerLogger::getInstance()->makeLog(log);
    mainWindow->setNumberOfClientsLabel(clientHandlers.size());
}

