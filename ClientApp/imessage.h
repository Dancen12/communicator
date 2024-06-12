#ifndef IMESSAGE_H
#define IMESSAGE_H
#include <string>
#include "user.h"
#include <QString>
#include <QDateTime>


class Imessage
{
public:
    Imessage(const User& senderVal, const std::string& postDateVal);
    virtual ~Imessage() = default;

     virtual std::string getMessage() const = 0;
    std::string getPostDate() const;
    User getSender() const;
    virtual operator QString() const = 0;
protected:
    User sender;
    std::string postDate;

};


#endif // IMESSAGE_H
