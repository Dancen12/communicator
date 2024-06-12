#include "textmessage.h"

TextMessage::TextMessage(const User& senderVal, const std::string& postDateVal, const std::string& textVal)
    : Imessage(senderVal,postDateVal), text(textVal)
{
}
std::string TextMessage:: getMessage() const
{
    return text;
}

TextMessage::operator QString () const
{
    return QString((postDate + ' ' + sender.personalInfo.name + ":" + getMessage()).c_str());
}
