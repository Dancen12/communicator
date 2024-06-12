#ifndef SINGLECHAT_H
#define SINGLECHAT_H
#include "ichat.h"
#include "filemanager.h"
#include "currentuser.h"
#include <thread>
#include <mutex>

#include "serverrequester.h"
#include "textmessage.h"

class MainWindow;





class SingleChat: public IChat
{
public:
    SingleChat(const CurrentUser& senderVal, const User& receiverVal, QObject *parent = nullptr);
    void start() override;
    void end() override;
    ~SingleChat();

    User sender;
    User receiver;
public slots:
    void sentMessage(Imessage* message) override;
    void newMessage(Imessage* message) override;
protected:
    bool upToDateMessages();
    void getMessagesFromServer();
    void showMessages();
    void updateFile();

    FileManager fileManager;
    std::list<Imessage*> messages;
    std::string lastMessage;
    bool stop;
};

#endif // SINGLECHAT_H
