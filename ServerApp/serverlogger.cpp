#include "serverlogger.h"
#include <QDateTime>
#include <QFile>
#include "dbmanager.h"

ServerLogger* ServerLogger::instance = nullptr;


ServerLogger* ServerLogger::getInstance()
{
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);
    if(!instance)
    {
        instance = new ServerLogger;
    }
    return instance;
}
void ServerLogger:: makeLog(const QString& event)
{
    QString log = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+'\t'+event;
    saveInFile(log);
    sendToDB(event);
    emit addToList(log);
}

 void ServerLogger::makeLogWithoutDB(const QString& event)
{
     QString log = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+'\t'+event;
     saveInFile(log);
     emit addToList(log);
}

void ServerLogger::makeLogOnlyToFile(const QString& event)
{
    QString log = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+'\t'+event;
    saveInFile(log);
}

void ServerLogger::sendToDB(const QString& log)
{
    DBManager::getInstance()->addLog(log.toStdString());
}
void ServerLogger::saveInFile(const QString& log)
{
    QFile file("logs.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << log << "\n";
        file.close();
    } else {
        throw std::runtime_error("Cannot open file to save log");
    }
}
