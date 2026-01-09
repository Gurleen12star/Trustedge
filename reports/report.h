#ifndef REPORT_H
#define REPORT_H

#include "../billing/invoice.h"
#include <vector>
#include <string>

class ReportService {
public:
    void addInvoice(const Invoice& invoice);

    double getTotalRevenue() const;
    int getTotalInvoices() const;
    int getPaidInvoices() const;
    int getPendingInvoices() const;

    void generateSummaryReport() const;

private:
    std::vector<Invoice> invoices;
};

#endif
