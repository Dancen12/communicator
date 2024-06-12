#include "user.h"

bool operator==(const User& lv, const User& rv )
{
    return lv.userID == rv.userID;
}
User::User()
{
    userID = 0;
}

User::User(int id,const std::string& nameVal,const std::string& surNameVal,const std::string& dateOfBirthVal,const std::string& lastLoggedVal,const std::string& lastMessageVal,const std::string& dateOfJoinVal,const std::string& emailVal, const std::string& bioVal)
{
    userID = id;

    personalInfo.name = nameVal;
    personalInfo.surname = surNameVal;
    personalInfo.dateOfBirth = dateOfBirthVal;

    userDates.dateOfJoin = dateOfJoinVal;
    userDates.lastMessage = lastMessageVal;
    userDates.lastLogged = lastLoggedVal;

    contacts.email = emailVal;

    additionalInfo.bio = bioVal;
}
User& User::operator=(const User& rv)
{
    userID = rv.userID;

    personalInfo.name = rv.personalInfo.name;
    personalInfo.surname = rv.personalInfo.surname;
    personalInfo.dateOfBirth = rv.personalInfo.dateOfBirth;

    userDates.dateOfJoin = rv.userDates.dateOfJoin;
    userDates.lastMessage = rv.userDates.lastMessage;
    userDates.lastLogged = rv.userDates.lastLogged;

    contacts.email = rv.contacts.email;

    additionalInfo.bio = rv.additionalInfo.bio;

    return *this;
}

User::User(const User& original)
{
    *this = original;
}
