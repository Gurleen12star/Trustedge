#ifndef PASSWORD_HASH_H
#define PASSWORD_HASH_H

#include <string>

class PasswordHash {
public:
    static std::string hash(const std::string& password);
    static bool verify(const std::string& password, const std::string& hash);
};

#endif
