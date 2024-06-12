#include "cryptographer.h"

Cryptographer::Cryptographer(ICipher* cipherVal)
{
    cipher = cipherVal;
}
void Cryptographer:: decrypt(std::string& str)
{
    if(cipher)
    {
        cipher->decrypt(str);
    }
}
void Cryptographer:: encrypt(std::string& str)
{
    if(cipher)
    {
        cipher->encrypt(str);
    }
}
void Cryptographer:: setCipher(ICipher* cipherVal)
{
    if(cipher)
    {
        delete cipher;
    }
    cipher = cipherVal;
}
Cryptographer::~Cryptographer()
{
    if(cipher)
    {
        delete cipher;
    }
}
