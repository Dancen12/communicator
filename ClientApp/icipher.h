#ifndef ICIPHER_H
#define ICIPHER_H

#include <string>
class ICipher
{
public:
    virtual void decrypt(std::string&) = 0;
    virtual void encrypt(std::string&) = 0;
    virtual ~ICipher();
};

#endif // ICIPHER_H
