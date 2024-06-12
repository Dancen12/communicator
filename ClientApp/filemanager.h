#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <vector>
#include <string>
#include "cryptographer.h"
#include "textmessage.h"
#include "currentuser.h"
#include "secretcipher.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDateTime>

class FileManager;
void createFile(const QString &, FileManager&);

class FileManager : public QObject
{
    Q_OBJECT
public:
    explicit FileManager(const CurrentUser& currentUserVal,QObject *parent = nullptr);

    std::list<Imessage*> getChat(const User& user);
    std::string chatLastUpdate(const User& user);
    void updateChatFile(const User& user, std::list<Imessage*>& messages);
    ~FileManager();

    friend void createFile(const QString &, FileManager&);
signals:

protected:
    QString encryptDataToFile( std::list<Imessage*>& messages);
    QString decryptFile(QFile&);
private:
    CurrentUser currentUser;
    Cryptographer cryptographer;

};



#endif // FILEMANAGER_H
