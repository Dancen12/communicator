#include "imessage.h"

Imessage::Imessage(const User& senderVal, const std::string& postDateVal): sender(senderVal), postDate(postDateVal)
{}

std::string Imessage::getPostDate() const
{
    return postDate;
}
User Imessage::getSender() const
{
    return sender;
}
