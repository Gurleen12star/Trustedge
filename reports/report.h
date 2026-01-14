#ifndef REPORT_H
#define REPORT_H

#include "../billing/invoice.h"
#include <vector>

class ReportService {
public:
    // Add invoice record into report system
    void addInvoice(const Invoice& invoice);

    // Analytics / Summary methods
    double getTotalRevenue() const;
    int getTotalInvoices() const;
    int getPaidInvoices() const;
    int getPendingInvoices() const;

    // Print a summary report on console
    void generateSummaryReport() const;

    // Return stored invoices (needed for exporting)
    const std::vector<Invoice>& getInvoices() const;

private:
    std::vector<Invoice> invoices;
};

#endif
