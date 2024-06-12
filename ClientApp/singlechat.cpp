#include "singlechat.h"
#include "mainwindow.h"

SingleChat::SingleChat(const CurrentUser& senderVal, const User& receiverVal, QObject *parent)
    : IChat(parent), sender(senderVal), receiver(receiverVal), fileManager(senderVal),stop(false) //thr(nullptr),
{
    messages = fileManager.getChat(receiver);
    lastMessage = fileManager.chatLastUpdate(receiver);
}

void SingleChat::sentMessage(Imessage* message)
{
    messages.push_back(message);
    emit updateMessagesSignal(std::list<Imessage*>{message});
    ServerRequester::getInstance()->sendMessage(sender.userID,receiver.userID,message->getPostDate(),message->getMessage());
}
void SingleChat:: newMessage(Imessage* message)
{
    messages.push_back(message);
    emit updateMessagesSignal(std::list<Imessage*>{message});
}

void SingleChat:: start()
{

    if(upToDateMessages())//nie aktualne, zle nazwana metoda
    {
        getMessagesFromServer();
    }
    showMessages();
    emit setChatNameSignal(receiver.personalInfo.name + ' ' + receiver.personalInfo.surname);
}
void SingleChat:: end()
{
    updateFile();
    emit clearChat();
}

bool SingleChat::upToDateMessages()
{
    return lastMessage<ServerRequester::getInstance()->lastUpdateMessages(sender.userID,receiver.userID);
}
void SingleChat:: getMessagesFromServer()
{
    std::list<Imessage*> newMessages = ServerRequester::getInstance()->GetMessagesNewerThanDate(sender.userID,receiver.userID,lastMessage);
    if(!newMessages.empty())
    {
        messages.splice(messages.end(),newMessages);
        lastMessage = messages.back()->getPostDate();
    }
}
void SingleChat::showMessages()
{
    emit showMessagesSignal(messages);
}
void SingleChat::updateFile()
{
    fileManager.updateChatFile(receiver,messages);
}



SingleChat::~SingleChat()
{
    for(auto& mess : messages )
    {
        delete mess;
    }
    messages.clear();
}
