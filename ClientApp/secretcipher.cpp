#include "secretcipher.h"

SecretCipher::SecretCipher(int keyVal)
{
    key = keyVal;
}
void SecretCipher::setKey(int keyVal)
{
    key = keyVal;
}
void SecretCipher::decrypt(std::string& str)
{
    for (auto& ch : str)
    {
        ch = ch ^ key;
    }
}
void SecretCipher::encrypt(std::string& str)
{
    for (auto& ch : str)
    {
        ch = ch ^ key;
    }
}
SecretCipher::~SecretCipher()
{

}
