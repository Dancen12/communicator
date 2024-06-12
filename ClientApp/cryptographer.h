#ifndef CRYPTOGRAPHER_H
#define CRYPTOGRAPHER_H
#include "icipher.h"
#include <string>

class Cryptographer
{
public:
    Cryptographer() = default;
    Cryptographer(ICipher*);
    void decrypt(std::string&);
    void encrypt(std::string&);
    void setCipher(ICipher*);
    virtual ~Cryptographer();
protected:
    ICipher* cipher;
private:
    Cryptographer& operator=(const Cryptographer& rv) = delete;
    Cryptographer(const Cryptographer&) = delete;
};

#endif // CRYPTOGRAPHER_H
