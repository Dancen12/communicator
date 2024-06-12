#ifndef SERVERREQUESTER_H
#define SERVERREQUESTER_H

#include <QObject>
#include <QTcpSocket>
#include <mutex>
#include "user.h"
#include <vector>
#include "ichat.h"
#include "textmessage.h"


#define SERVERIP "127.0.0.1"
#define SERVERPORT 1234
#define EMPTYROW "EMPTYROW"
//singleton
class MainWindow;

class ServerRequester : public QObject
{
    Q_OBJECT
public:
    ServerRequester& operator=(const ServerRequester&) = delete;
    ServerRequester(const ServerRequester&) = delete;


    void connectSer();
    void disconnectSer();
    bool isCorrectLogin(const std::string& login, const std::string& password);
    QStringList  getUserData(const std::string& email);
    std::list<User> getUsers(int userID);
    std::list<Imessage*> GetMessagesNewerThanDate(int sender_id,int receiver_id, const std::string& date);
    std::list<User> serchUser(const std::string& name, const std::string& surname);
    std::string lastUpdateMessages(int sender_id, int receiver_id);
    void connectToMessages(MainWindow*);
    void sendMessage(int sender_id, int receiver_id,const std::string& date, const std::string& content);
    bool emailExist(const std::string& email );
    void signInUser(const std::string& pass, const std::string& name, const std::string& surname,
                    const std::string& dateOfBirth, const std::string& phone, const std::string& email,
                    const std::string& bio);
    void changePassword(int userID, const std::string& password);
    void changeName(int userID, const std::string& name);
    void changeSurname(int userID, const std::string& surname);

    static ServerRequester* getInstance(QObject *parent = nullptr);
    ~ServerRequester();
signals:
    void newMessage(QString);
public slots:
    void connected();
    void disconnected();
    void onErrorOccurred(QAbstractSocket::SocketError socketError);
    void newDataCome();
protected:
    explicit ServerRequester(QObject *parent = nullptr);


    static ServerRequester * pInstance;
    static std::mutex mtx;
    QTcpSocket* socket;
};

#endif // SERVERREQUESTER_H
