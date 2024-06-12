#ifndef USER_H
#define USER_H
#include<string>

class User
{
public:
    User();
    ~User() = default;
    User(int id, const std::string& nameVal,const std::string& surNameVal,const std::string& dateOfBirthVal,const std::string& lastLoggedVal,const std::string& lastMessageVal,const std::string& dateOfJoinVal,const std::string& emailVal, const std::string& bioVal);
    User(const User& original);
    User& operator=(const User& rv);
    struct PersonalInfo
    {
        PersonalInfo() = default;
        PersonalInfo(const std::string& nameVal,const std::string& surNameVal,const std::string& dateOfBirthVal);
        std::string name;
        std::string surname;
        std::string dateOfBirth;
    };
    struct UserDates
    {
        UserDates() = default;
        UserDates(const std::string& lastLoggedVal,const std::string& dateOfJoinVal);
        std::string lastLogged;
        std::string lastMessage;
        std::string dateOfJoin;
    };
    struct Contacts
    {
        Contacts() = default;
        Contacts(const std::string& emailVal);
        std::string email;

    };
    struct AdditionalInfo
    {
        AdditionalInfo() = default;
        AdditionalInfo(const std::string& bioVal);
        std::string bio;
    };
    PersonalInfo personalInfo;
    UserDates userDates;
    Contacts contacts;
    AdditionalInfo additionalInfo;
    int userID;
};

bool operator==(const User&, const User& );

#endif // USER_H
