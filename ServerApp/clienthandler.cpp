#include "clienthandler.h"
#include <thread>
#include <chrono>
#include <QRandomGenerator>
#include <serverlogger.h>

ClientHandler::ClientHandler(QTcpSocket* socketVal, QObject *parent)
    : QObject{parent}, userID(0), socket(socketVal),stop(false)//,t(nullptr)
{
    connect(socket,&QTcpSocket::readyRead,this,&ClientHandler::read);
    methods.push_back(&ClientHandler::greetings);//0
    methods.push_back(&ClientHandler::isCorrectLogin);//1
    methods.push_back(&ClientHandler::getUserData);//2
    methods.push_back(&ClientHandler::endConnection);//3
    methods.push_back(&ClientHandler::getUsers);//4
    methods.push_back(&ClientHandler::GetMessagesNewerThanDate);//5
    methods.push_back(&ClientHandler::searchUsers);//6
    methods.push_back(&ClientHandler::lastUpdateMessages);//7
    methods.push_back(&ClientHandler::sendMessage);//8
    methods.push_back(&ClientHandler::emailExist);//9
    methods.push_back(&ClientHandler::addNewUser);//10
    methods.push_back(&ClientHandler::changePassword);//11
    methods.push_back(&ClientHandler::changeName);//12
    methods.push_back(&ClientHandler::changeSurname);//13
    ServerLogger::getInstance()->makeLogOnlyToFile("new client handler created");
}

 ClientHandler::~ClientHandler()
{
    stop = true;
    if(socket)
    {
        socket->disconnectFromHost();
        socket->deleteLater();
    }
    QString log = QString::fromStdString("~ClientHandler id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

QTcpSocket* ClientHandler:: getSocket()
{
    return socket;
}

void ClientHandler:: read()
{
    std::mutex mtx;
    mtx.lock();
    tasks.push(socket->readAll());
    mtx.unlock();
}


void ClientHandler:: serve()
{
    while(!stop)
    {
        if(!tasks.empty())
        {
            std::mutex mtx;
            mtx.lock();
            dataFromClient = tasks.front();
            tasks.pop();
            mtx.unlock();

            //get index
            QString temp (dataFromClient[0]);
            temp+=dataFromClient[1];
            int index = temp.toInt();
            dataFromClient.remove(0,2);
            (this->*methods[index])();
        }
    }
}

void ClientHandler::serveClient()
{
    serve();
    emit finished(this);
}

void ClientHandler:: greetings()
{
    qDebug() <<"Greetings: " << dataFromClient;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    qDebug() <<"Greetings end";
}

void ClientHandler:: isCorrectLogin()
{
    QString temp = dataFromClient;
    auto list =  temp.split(' ');
    std::string login = list[0].toStdString();
    std::string password = list[1].toStdString();
    if(DBManager::getInstance()->isCorrectLogin(login, password))
    {
        socket->write("1");
    }
    else
    {
        socket->write("0");
    }
    socket->flush();
    QString log = QString::fromStdString("isCorrectLogin id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

void ClientHandler:: getUserData()
{
    auto result = DBManager::getInstance()->getUSerData(dataFromClient.toStdString());
    //przypisanie id zalogowanego uzytkownika
    auto pos = result.toStdString().find_first_of('/');
    std::string temp(result.toStdString(),0,pos);
    userID = QString(temp.c_str()).toInt();
    socket->write(result.toStdString().c_str());
    socket->flush();
    QString log = QString::fromStdString("getUserData id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

void ClientHandler:: endConnection()
{
    stop = true;
}

void ClientHandler:: getUsers()
{
    auto result = DBManager::getInstance()->getUsers(dataFromClient.toInt());
    if(result.isEmpty())
    {
        socket->write(EMPTYROW);
        socket->flush();
    }
    else
    {
        socket->write(result.toStdString().c_str());
        socket->flush();
    }
    QString log = QString::fromStdString("getUsers id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

void ClientHandler:: GetMessagesNewerThanDate()
{
    QStringList list = QString(dataFromClient).split('/');
    auto result = DBManager::getInstance()->GetMessagesNewerThanDate(list.value(0).toInt(),list.value(1).toInt(),list.value(2).toStdString());
    if(result.isEmpty())
    {
        socket->write(EMPTYROW);
        socket->flush();
    }
    else
    {
        socket->write(result.toStdString().c_str());
        socket->flush();
    }
    QString log = QString::fromStdString("getMessageNewerThanDate id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

void ClientHandler::searchUsers()
{
    QStringList list = QString(dataFromClient).split('/');
    auto result = DBManager::getInstance()->searchUsers(list.value(0).toStdString(),list.value(1).toStdString());
    if(result.isEmpty())
    {
        socket->write(EMPTYROW);
        socket->flush();
    }
    else
    {
        socket->write(result.toStdString().c_str());
        socket->flush();
    }
    QString log = QString::fromStdString("searchUsers id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

void ClientHandler::lastUpdateMessages()
{
    auto id = dataFromClient.split('/');
    auto result = DBManager::getInstance()->lastUpdateMessages(id.at(0).toInt(),id.at(1).toInt());
    if(result.isEmpty())
    {
        socket->write(EMPTYROW);
        socket->flush();
    }
    else
    {
        socket->write(result.toStdString().c_str());
        socket->flush();
    }
    QString log = QString::fromStdString("lastUpdateMessage id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

void ClientHandler:: sendMessage()
{
    auto message = dataFromClient.split('/');
    int sender_id = message.at(0).toInt();
    int receiver_id = message.at(1).toInt();
    std::string date = message.at(2).toStdString();
    std::string content = message.at(3).toStdString();
    DBManager::getInstance()->addMessage(sender_id,receiver_id,date,content);
    emit sendMessage(sender_id,receiver_id,date,content);
    QString log = QString::fromStdString("sendMessage id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

void ClientHandler:: newMessageArrived(int sender_id, int receiver_id,const std::string& date, const std::string& message)
{
    //<m>/sid/rid/dat/con/
    std::string messageToHost("<m>");
    messageToHost+='/'+std::to_string(sender_id)+'/'+std::to_string(receiver_id)+'/'+date+'/'+message+'/';
    std::mutex mtx;
    mtx.lock();
    socket->write(messageToHost.c_str());
    socket->flush();
    mtx.unlock();
    QString log = QString::fromStdString("newMessageArrived id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

void ClientHandler::emailExist()
{
    if(DBManager::getInstance()->emailExist(dataFromClient.toStdString()))
    {
        socket->write("1");
    }
    else
    {
        socket->write("0");
    }
    socket->flush();
    QString log = QString::fromStdString("emailExist id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

void ClientHandler:: addNewUser()
{
    auto message = dataFromClient.split('/');
    std::string pass = message.at(0).toStdString();
    int key = QRandomGenerator::global()->bounded(1, 127);
    std::string name = message.at(1).toStdString();
    std::string surname = message.at(2).toStdString();
    std::string dateOfBirth = message.at(3).toStdString();
    std::string phone = message.at(4).toStdString();
    std::string email = message.at(5).toStdString();
    std::string bio = message.at(6).toStdString();
    DBManager::getInstance()->insertNewUser(pass, key, name, surname, dateOfBirth, phone, email, bio);
    QString log = QString::fromStdString("addNewUser id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}

void ClientHandler::changePassword()
{
    auto idAndPass = dataFromClient.split('/');
    DBManager::getInstance()->changePassword(idAndPass.at(0).toInt(),idAndPass.at(1).toStdString());
    QString log = QString::fromStdString("changePassword id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}
void ClientHandler::changeName()
{
    auto idAndName = dataFromClient.split('/');
    DBManager::getInstance()->changeName(idAndName.at(0).toInt(),idAndName.at(1).toStdString());
    QString log = QString::fromStdString("chnageName id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}
void ClientHandler::changeSurname()
{
    auto idAndSurname = dataFromClient.split('/');
    DBManager::getInstance()->changeSurname(idAndSurname.at(0).toInt(),idAndSurname.at(1).toStdString());
    QString log = QString::fromStdString("changeSurname id: " + std::to_string(userID) + ", ip: "+ socket->peerAddress().toString().toStdString());
    ServerLogger::getInstance()->makeLogOnlyToFile(log);
}
