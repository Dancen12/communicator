#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <string>
#include <mutex>
#include <QSql>
#include <QSqlDatabase>
#include <stdexcept>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>

#define DBNAME "MessengerDBTest"
#define DBHOSTNAME "127.0.0.1"
#define DBPORT 3306
#define DBUSERNAME "root"
#define DBPASSWORD ""

QString sqlErrorToString(const QSqlError &error);


class DBManager : public QObject
{
    Q_OBJECT
public:

    bool isCorrectLogin(const std::string& login, const std::string& password);
    QString getUSerData(std::string userEmail);
    QString getUsers(int user_id);
    QString GetMessagesNewerThanDate(int sender_id, int receiver_id, const std::string& date);
    QString searchUsers( const std::string& name, const std::string& surname);
    QString lastUpdateMessages(int sender_id, int receiver_id);
    void addMessage(int sender_id, int receiver_id, const std::string& date, const std::string& content);
    bool emailExist(const std::string& email);
    void insertNewUser(const std::string& pass, int key,const std::string& name, const std::string& surname,
                       const std::string& dateOfBirth, const std::string& phone, const std::string& email,
                       const std::string& bio);
    void changePassword(int userID, const std::string& password);
    void changeName(int userID, const std::string& name);
    void changeSurname(int userID, const std::string& surname);
    void addLog(const std::string&);


    void endConnection();

    static DBManager* getInstance();
    DBManager(const DBManager&)=delete;
    DBManager& operator=(const DBManager&)=delete;
    ~DBManager();

signals:

protected:
    static DBManager * dbInstance;
    static std::mutex mtx;
    QSqlDatabase dbConnection;


    explicit DBManager(QObject *parent = nullptr);
};

#endif // DBMANAGER_H
