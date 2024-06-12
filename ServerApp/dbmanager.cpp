#include "dbmanager.h"
#include <QDateTime>
#include "serverlogger.h"

QString sqlErrorToString(const QSqlError &error) {
    return QString("Error type: %1\nDriver error message: %2\nDatabase error message: %3\nNative error code: %4")
        .arg(error.type())
        .arg(error.driverText())
        .arg(error.databaseText())
        .arg(error.nativeErrorCode());
}

DBManager* DBManager::dbInstance =nullptr;
std::mutex DBManager::mtx;

DBManager::DBManager(QObject *parent)
    : QObject{parent}
{
    dbConnection = QSqlDatabase::addDatabase("QMYSQL");
    dbConnection.setDatabaseName(DBNAME);
    dbConnection.setHostName(DBHOSTNAME);
    dbConnection.setUserName(DBUSERNAME);
    dbConnection.setPassword(DBPASSWORD);
    dbConnection.setPort(DBPORT);

    if(!dbConnection.open())
    {
        ServerLogger::getInstance()->makeLogWithoutDB("Cannot open database");
        throw std::runtime_error("Cannot open database");
    }
    ServerLogger::getInstance()->makeLogWithoutDB("Database open");
}

DBManager::~DBManager()
{
    dbConnection.close();
    ServerLogger::getInstance()->makeLogWithoutDB("Database close");
}

DBManager* DBManager::getInstance()
{
    mtx.lock();
    if(!dbInstance)
    {
        dbInstance = new DBManager;
    }
    mtx.unlock();
    return dbInstance;
}

bool DBManager::isCorrectLogin(const std::string& login, const std::string& password)
{
    QString temp = QString("SELECT * FROM security s JOIN contacts c ON c.user_id = s.user_id WHERE c.email = '%1' AND s.password = '%2';")
                        .arg(login.c_str())
                        .arg(password.c_str());
    mtx.lock();
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    bool ans = false;
    if(query.exec())
    {
        if(query.next())
        {
            ans = true;
        }
    }
    else
    {
        ServerLogger::getInstance()->makeLog("query not performed");
    }
    mtx.unlock();
    return ans;
}

QString DBManager:: getUSerData(std::string userEmail)
{
    QString temp = QString("SELECT u.user_id, pd.name, pd.surname, up.bio, s.key FROM Users u JOIN PersonalData pd ON u.user_id = pd.user_id JOIN UserProfile up ON u.user_id = up.user_id JOIN Security s ON u.user_id = s.user_id JOIN contacts c ON c.user_id = u.user_id WHERE c.email = '%1';")
                    .arg(userEmail.c_str());
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
    if(!query.next())
    {
        ServerLogger::getInstance()->makeLog("Empty row in getUserData");
        throw std::runtime_error("Empty row in getUserData");
    }
    QString result;
    for(int i =0; i < 5; ++i)
    {
        result+=query.value(i).toString() + '/';
    }
    return result;
}

QString DBManager::getUsers(int user_id)
{
    QString temp = QString("SELECT pd.user_id, pd.name, pd.surname FROM messages m ");
    temp += "INNER JOIN personaldata pd ON pd.user_id = CASE WHEN m.sender_id = %1 THEN m.receiver_id WHEN m.receiver_id = %1 THEN m.sender_id END ";
    temp += "WHERE m.sender_id = %1 OR m.receiver_id = %1 GROUP BY pd.user_id, pd.name, pd.surname ORDER BY MAX(m.postDate) DESC;";
    temp = temp.arg(user_id);
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
    QString result;
    while(query.next())
    {
        for(int i = 0; i < 3;++i)
        {
            result+=query.value(i).toString() +'/';
        }
        result+='\n';
    }
    return result;
}

QString DBManager::GetMessagesNewerThanDate(int sender_id,int receiver_id, const std::string& date)
{
    QString temp = QString("SELECT sender_id, name, surname, postDate, content FROM Messages ");
    temp+= "JOIN personalData ON personalData.user_id = messages.sender_id ";
    temp+= "WHERE ((sender_id = %1 AND receiver_id = %2) OR (sender_id = %2 AND receiver_id = %1))";
    temp+= " AND postDate > '"+date+"' ORDER BY postDate;";
    temp = temp.arg(sender_id).arg(receiver_id);
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
    QString result;
    if(query.next())
    {
        query.previous();
        while(query.next())
        {
            for(int i = 0; i < 5;++i)
            {
                result+=query.value(i).toString() +'/';
            }
            result+='\n';
        }
    }
    return result;
}
QString DBManager:: searchUsers(const std::string& name, const std::string& surname)
{
    QString temp = QString("SELECT pd.user_id, pd.name, pd.surname FROM personaldata pd");
    temp+= " WHERE pd.name LIKE CONCAT('"+name+"','"+surname+"','%');";
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
    QString result;
    if(query.next())
    {
        query.previous();
        while(query.next())
        {
            for(int i = 0; i < 3;++i)
            {
                result+=query.value(i).toString() +'/';
            }
            result+='\n';
        }
    }
    return result;
}

QString DBManager:: lastUpdateMessages(int sender_id, int receiver_id)
{
    QString temp = QString("SELECT m.postDate FROM messages m");
    temp+= " WHERE (m.sender_id = %1 AND m.receiver_id = %2) OR (m.sender_id = %2 AND m.receiver_id = %1)";
    temp+= "ORDER BY m.postDate DESC LIMIT 1;";
    temp = temp.arg(sender_id).arg(receiver_id);
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
    QString result;
    if(query.next())
    {
        result = query.value(0).toString();
    }
    result = result.split('T').join(' ');
    return result;
}

void DBManager:: addMessage(int sender_id, int receiver_id, const std::string& date, const std::string& content)
{
    QString temp = QString("INSERT INTO messages ( sender_id, receiver_id, postDate, content)");
    temp+= " VALUES (%1,%2,'"+date+"','"+content+"');";
    temp = temp.arg(sender_id).arg(receiver_id);
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
}

bool DBManager:: emailExist(const std::string& email)
{
    QString temp = QString("SELECT c.user_id FROM contacts c WHERE c.email = '");
    temp+= email +"';";
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
    if(query.next())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DBManager::insertNewUser(const std::string& pass, int key,const std::string& name, const std::string& surname,
                   const std::string& dateOfBirth, const std::string& phone, const std::string& email,
                   const std::string& bio)
{
    std::string date = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString();
    QString temp = QString("CALL InsertNewUser('");
    temp+= pass+"','"+std::to_string(key)+"','"+name+"','"+surname+"','"+dateOfBirth+"','"+phone+"','"+email+"','"+date+
            "','"+"','"+bio+"');";
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
}

void DBManager::changePassword(int userID, const std::string& password)
{
    QString temp = QString("UPDATE security SET password =");
    temp+=" '"+password+"' WHERE user_id = %1;";
    temp = temp.arg(userID);
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
}
void DBManager::changeName(int userID, const std::string& name)
{
    QString temp = QString("UPDATE personalData SET name =");
    temp+=" '"+name+"' WHERE user_id = %1;";
    temp = temp.arg(userID);
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
}
void DBManager::changeSurname(int userID, const std::string& surname)
{
    QString temp = QString("UPDATE personalData SET surname =");
    temp+=" '"+surname+"' WHERE user_id = %1;";
    temp = temp.arg(userID);
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
}

void DBManager::addLog(const std::string& log)
{
    QString temp = QString("INSERT INTO serverlogs (date, operation) VALUES (NOW(), ");
    temp+="'"+log+"');";
    QSqlQuery query(dbConnection);
    query.prepare(temp);
    mtx.lock();
    if(!query.exec())
    {
        ServerLogger::getInstance()->makeLog("query not performed");
        mtx.unlock();
        throw std::runtime_error(sqlErrorToString(query.lastError()).toStdString());
    }
    mtx.unlock();
}
