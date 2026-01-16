#ifndef AUDIT_LOG_H
#define AUDIT_LOG_H

#include <string>

class AuditLog {
public:
    // Logs action with timestamp into logs/audit.log
    static void log(const std::string& username, const std::string& action);

private:
    static std::string getCurrentTimestamp();
};

#endif
