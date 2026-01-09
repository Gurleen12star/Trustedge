#include "auth.h"
#include "password_hash.h"
#include <iostream>
#include <vector>

// Simulated user database (will move to DB later)
static std::vector<User> users = {
    {"U001", "admin",   PasswordHash::hash("admin123"),   Role::ADMIN},
    {"U002", "finance", PasswordHash::hash("fin123"),     Role::FINANCE},
    {"U003", "staff",   PasswordHash::hash("staff123"),   Role::STAFF}
};

AuthService::AuthService() {
    loggedIn = false;
}

User AuthService::findUser(const std::string& username) {
    for (const auto& user : users) {
        if (user.username == username) {
            return user;
        }
    }
    return {"", "", "", Role::CUSTOMER};
}

bool AuthService::login(const std::string& username, const std::string& password) {
    User user = findUser(username);

    if (user.username.empty()) {
        std::cout << "User not found\n";
        return false;
    }

    if (PasswordHash::verify(password, user.passwordHash)) {
        currentUser = user;
        loggedIn = true;
        std::cout << "Login successful: " << username << "\n";
        return true;
    }

    std::cout << "Invalid password\n";
    return false;
}

void AuthService::logout() {
    loggedIn = false;
}

bool AuthService::isAuthenticated() const {
    return loggedIn;
}

Role AuthService::getUserRole() const {
    return currentUser.role;
}

std::string AuthService::getCurrentUsername() const {
    return currentUser.username;
}
