#include "report.h"
#include <iostream>

void ReportService::addInvoice(const Invoice& invoice) {
    invoices.push_back(invoice);
}

double ReportService::getTotalRevenue() const {
    double total = 0.0;
    for (const auto& inv : invoices) {
        if (inv.status == InvoiceStatus::PAID) {
            total += inv.totalAmount;
        }
    }
    return total;
}

int ReportService::getTotalInvoices() const {
    return invoices.size();
}

int ReportService::getPaidInvoices() const {
    int count = 0;
    for (const auto& inv : invoices) {
        if (inv.status == InvoiceStatus::PAID) {
            count++;
        }
    }
    return count;
}

int ReportService::getPendingInvoices() const {
    int count = 0;
    for (const auto& inv : invoices) {
        if (inv.status == InvoiceStatus::PENDING) {
            count++;
        }
    }
    return count;
}

void ReportService::generateSummaryReport() const {
    std::cout << "\n===== BILLING SUMMARY REPORT =====\n";
    std::cout << "Total Invoices  : " << getTotalInvoices() << "\n";
    std::cout << "Paid Invoices   : " << getPaidInvoices() << "\n";
    std::cout << "Pending Invoices: " << getPendingInvoices() << "\n";
    std::cout << "Total Revenue   : ₹" << getTotalRevenue() << "\n";
    std::cout << "=================================\n";
}
