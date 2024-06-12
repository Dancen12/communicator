#ifndef CURRENTUSER_H
#define CURRENTUSER_H
#include "user.h"

class CurrentUser: public User
{
public:
    CurrentUser() = default;
    CurrentUser(int id, const std::string& nameVal,const std::string& surNameVal,const std::string& dateOfBirthVal,const std::string& lastLoggedVal,const std::string& lastMessageVal,const std::string& dateOfJoinVal,const std::string& emailVal, const std::string& bioVal, const std::string& passwordVal, int keyVal);
    CurrentUser(const CurrentUser& original);
    CurrentUser& operator=(const CurrentUser& rv);
    struct Safety
    {
        Safety() = default;
        Safety(int keyVal, const std::string& passwordVal);
        int key;
        std::string password;
    };
    Safety safety;
};

#endif // CURRENTUSER_H
