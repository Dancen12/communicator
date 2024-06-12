#include "currentuser.h"
CurrentUser::CurrentUser(int id, const std::string& nameVal,const std::string& surNameVal,const std::string& dateOfBirthVal,const std::string& lastLoggedVal,const std::string& lastMessageVal,const std::string& dateOfJoinVal,const std::string& emailVal, const std::string& bioVal, const std::string& passwordVal, int keyVal)
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

    safety.password = passwordVal;
    safety.key = keyVal;
}

CurrentUser::CurrentUser(const CurrentUser& original)
{
    *this = original;
}
CurrentUser& CurrentUser:: operator=(const CurrentUser& rv)
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

    safety.key = rv.safety.key;
    safety.password = rv.safety.password;

    return *this;
}
