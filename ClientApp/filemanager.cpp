#include "filemanager.h"


void createFile(const QString & filename, FileManager& fm)
{
    QFile file(filename);
    if(!file.exists())
    {
        file.open(QIODevice::WriteOnly);
        QTextStream str(&file);
        std::string date = "1000-01-01 00:00:00\n";
        fm.cryptographer.encrypt(date);
        str << date.c_str();
        fm.cryptographer.decrypt(date);
        file.close();
    }
}

FileManager::FileManager(const CurrentUser& currentUserVal,QObject *parent)
    : QObject{parent}, currentUser(currentUserVal), cryptographer(new SecretCipher(currentUserVal.safety.key))
{
}

std::list<Imessage*> FileManager::getChat(const User& user)
{
    QString filename("chats/");
    filename += currentUser.personalInfo.surname + std::to_string(currentUser.userID);
    filename+= '_'+ user.personalInfo.surname + std::to_string(user.userID) + ".txt";
    QFile file(filename);
    if(!file.exists())
    {
        createFile(filename,*this);
        std::list<Imessage*> v;
        return v;
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        exit(-1);
    }
    QString decryptedData = decryptFile(file);
    QTextStream textstr(&decryptedData);
    textstr.readLine();//last update date
    std::list<Imessage*> chat;
    while(!textstr.atEnd())
    {
        QString id,postdate, postTime,content;
        textstr >> id;
        textstr >> postdate;
        char ch = 0;
        textstr >> ch;
        textstr >> postTime;
        postdate += ' ' +postTime;
        content = textstr.readLine();
        if(id.toInt() == currentUser.userID)
        {
            chat.push_back(new TextMessage(currentUser,postdate.toStdString(), content.toStdString()));
        }
        else
        {
            chat.push_back(new TextMessage(user,postdate.toStdString(), content.toStdString()));
        }
    }
    return chat;
}

std::string FileManager::chatLastUpdate(const User& user)
{
    QString filename("chats/");
    filename += currentUser.personalInfo.surname + std::to_string(currentUser.userID);
    filename+= '_'+ user.personalInfo.surname + std::to_string(user.userID) + ".txt";
    QFile file(filename);
    if(!file.exists())
    {
        createFile(filename,*this);
        return "1000-01-01 00:00:00";
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        exit(-1);
    }

    std::list<Imessage*> chat;
    QString decryptedData = decryptFile(file);
    QTextStream textstr(&decryptedData);
    std::string date = textstr.readLine().toStdString();
    return date;
}

void FileManager::updateChatFile(const User& user, std::list<Imessage*>& messages)
{
    if(messages.empty())
    {
        return;
    }
    QString filename("chats/");
    filename += currentUser.personalInfo.surname + std::to_string(currentUser.userID);
    filename+= '_'+ user.personalInfo.surname + std::to_string(user.userID) + ".txt";
    QFile file(filename);
    if(!file.exists())
    {
        createFile(filename,*this);
    }
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        exit(-1);
    }
    QString encryptedData = encryptDataToFile(messages);
    QTextStream out(&file);
    out << encryptedData;
    file.close();
}


QString FileManager::encryptDataToFile(std::list<Imessage*>& messages)
{
    std::string dataToFile = messages.back()->getPostDate() + '\n';//date
    for(auto& message : messages)
    {
        std::string row = std::to_string(message->getSender().userID)
                          + ' ' + message->getPostDate()
                          + ' ' + message->getMessage() + '\n';
        dataToFile+=row;
    }
    cryptographer.encrypt(dataToFile);
    return QString::fromStdString(dataToFile);
}
QString FileManager::decryptFile(QFile& file)
{
    std::string encryptedData = file.readAll().toStdString();
    cryptographer.decrypt(encryptedData);
    return QString::fromStdString(encryptedData);
}
FileManager::~FileManager()
{

}
