#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include "clienthandler.h"
#include <list>
#include <thread>

#define IPADRESS "127.0.0.1"
#define PORT 1234

class MainWindow;

class Server :public QTcpServer
{
private:
    Server();
    Server(const Server& ) = delete;
    Server& operator=(const Server&) = delete;
    MainWindow* mainWindow = nullptr;
    static std::list<ClientHandler *> clientHandlers;
    static Server* server;

protected:
    void incomingConnection(qintptr socketDescriptor) override;

public slots:
    void deleteHandler(ClientHandler*);
    void forwardMessage(int, int,const std::string&, const std::string&);
public:
    void setMainWindowPtr(MainWindow*);
    virtual ~Server();
    static Server* getInstance();
    void process();
    void stop();
};


#endif // SERVER_H
