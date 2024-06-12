#ifndef SERVERLOGGER_H
#define SERVERLOGGER_H

#include <QObject>
#include <mutex>

class MainWindow;


class ServerLogger : public QObject
{
    Q_OBJECT
public:
    ServerLogger(const ServerLogger&) = delete;
    ServerLogger& operator=(const ServerLogger&) = delete;

    static ServerLogger* getInstance();
    void makeLog(const QString&);
    void makeLogWithoutDB(const QString&);
    void makeLogOnlyToFile(const QString&);
protected:
    void saveInFile(const QString&);
    void sendToDB(const QString&);
signals:
    void addToList(const QString&);
private:
    static ServerLogger* instance;
    //explicit ServerLogger(QObject *parent = nullptr);
    ServerLogger() = default;
};

#endif // SERVERLOGGER_H
