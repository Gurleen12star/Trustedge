#include "password_hash.h"

// Simple placeholder hashing (can be upgraded later)
std::string PasswordHash::hash(const std::string& password) {
    return "HASHED_" + password;
}

bool PasswordHash::verify(const std::string& password, const std::string& hash) {
    return hash == hash(password);
}
