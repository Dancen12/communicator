#ifndef ICHAT_H
#define ICHAT_H

#include <QObject>
#include "imessage.h"
#include <vector>


class IChat : public QObject
{
    Q_OBJECT
public:
    explicit IChat(QObject *parent = nullptr);
    virtual void start() = 0;
    virtual void end() = 0;
signals:
    //wysylane do mainWindow
    void showMessagesSignal(std::list<Imessage*> messages);
    void updateMessagesSignal(std::list<Imessage*> messages);
    void setChatDescriptionSignal(std::string description);
    void setChatNameSignal(std::string chatName);
    void clearChat();
public slots:
    //otrzymane z mainWindow
    virtual void sentMessage(Imessage* message) = 0;
    virtual void newMessage(Imessage* message) = 0;
};

#endif // ICHAT_H
