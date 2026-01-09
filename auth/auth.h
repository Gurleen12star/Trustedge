#ifndef AUTH_H
#define AUTH_H

#include <string>

// Roles used across the system
enum class Role {
    ADMIN,
    FINANCE,
    STAFF,
    AUDITOR,
    CUSTOMER
};

// User model
struct User {
    std::string userId;
    std::string username;
    std::string passwordHash;
    Role role;
};

// Authentication service
class AuthService {
public:
    AuthService();

    bool login(const std::string& username, const std::string& password);
    void logout();

    bool isAuthenticated() const;
    Role getUserRole() const;
    std::string getCurrentUsername() const;

private:
    User currentUser;
    bool loggedIn;

    User findUser(const std::string& username);
};

#endif
