#include "auth/auth.h"
#include "billing/billing.h"
#include "billing/invoice.h"
#include "reports/report.h"
#include "reports/exporter.h"

#include <iostream>

int main() {
    AuthService auth;
    BillingService billing;
    ReportService report;

    std::cout << "=== TrustLedger Demo ===\n";

    // ✅ Login
    if (!auth.login("admin", "admin123")) {
        std::cout << "Login failed! Exiting...\n";
        return 0;
    }

    std::cout << "Logged in as: " << auth.getCurrentUsername() << "\n";

    // ✅ Generate invoices
    Invoice inv1 = billing.generateInvoice("CUST_101", 1000.0, 0.18, 50.0);
    billing.markAsPaid(inv1);

    Invoice inv2 = billing.generateInvoice("CUST_102", 2000.0, 0.18, 0.0);
    // Not paid (Pending)

    Invoice inv3 = billing.generateInvoice("CUST_103", 500.0, 0.18, 20.0);
    billing.markAsPaid(inv3);

    // ✅ Add invoices to report
    report.addInvoice(inv1);
    report.addInvoice(inv2);
    report.addInvoice(inv3);

    // ✅ Print summary report
    report.generateSummaryReport();

    // ✅ Export to CSV
    ReportExporter::exportToCSV(report.getInvoices(), "billing_report.csv");

    std::cout << "\n✅ Done! Check file: billing_report.csv\n";
    return 0;
}
