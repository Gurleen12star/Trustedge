#include "audit_log.h"
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

std::string AuditLog::getCurrentTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void AuditLog::log(const std::string& username, const std::string& action) {
    std::ofstream file("logs/audit.log", std::ios::app);

    if (!file.is_open()) {
        std::cout << "❌ Failed to open audit log file!\n";
        return;
    }

    file << "[" << getCurrentTimestamp() << "] "
         << "USER: " << username
         << " | ACTION: " << action << "\n";

    file.close();
}
