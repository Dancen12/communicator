#ifndef SECRETCIPHER_H
#define SECRETCIPHER_H

#include "icipher.h"
class SecretCipher: public ICipher
{
public:
    SecretCipher(int);
    void setKey(int);
    void decrypt(std::string&) override;
    void encrypt(std::string&) override;
    ~SecretCipher() override;
protected:
    int key;
};

#endif // SECRETCIPHER_H
