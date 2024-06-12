#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QObject>
#include <QTcpSocket>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>
#include "dbmanager.h"
#define EMPTYROW "EMPTYROW"


//Pierwsze dwa bajty to nr operacji. pozostale to dane potrzebe do operacji; nr operacji jest nr indexu
//w vectorze metod
//wszystkie metody maja struktore
//void name();

class ClientHandler : public QObject
{
    Q_OBJECT
public:
    int userID;
    ClientHandler(QTcpSocket* socketVal, QObject *parent = nullptr);
    void serveClient();
    void newMessageArrived(int sender_id, int receiver_id,const std::string& date, const std::string& message);
    ~ClientHandler();
    QTcpSocket* getSocket();
protected slots:
    void read();
signals:
    void finished(ClientHandler*);
    void sendMessage(int, int,const std::string&, const std::string&);
protected:
    typedef void (ClientHandler::*MethodPtr)();

    void serve();

    void greetings();
    void isCorrectLogin();
    void getUserData();
    void endConnection();
    void getUsers();
    void GetMessagesNewerThanDate();
    void searchUsers();
    void lastUpdateMessages();
    void sendMessage();
    void emailExist();
    void addNewUser();
    void changePassword();
    void changeName();
    void changeSurname();



    QTcpSocket* socket;
    bool stop;
    //std::thread* t;
    QByteArray dataFromClient;
    std::vector<MethodPtr> methods; //o tej samej struktorze; moze void po prostu i jako parametr TextStrem z socketa?
    std::queue<QByteArray> tasks;
};

#endif // CLIENTHANDLER_H
