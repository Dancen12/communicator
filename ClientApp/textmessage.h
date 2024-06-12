#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H
#include "imessage.h"


class TextMessage: public Imessage
{
public:
    TextMessage() = delete;
    TextMessage(const User& senderVal, const std::string& postDateVal, const std::string& textVal);
    std::string getMessage() const override;
    operator QString () const override;
protected:
    std::string text;
};

#endif // TEXTMESSAGE_H
