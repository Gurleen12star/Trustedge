#ifndef INVOICE_H
#define INVOICE_H

#include <string>

enum class InvoiceStatus {
    PENDING,
    PAID,
    CANCELLED
};

struct Invoice {
    std::string invoiceId;
    std::string customerId;

    double baseAmount;
    double taxAmount;
    double discountAmount;
    double totalAmount;

    InvoiceStatus status;
};

// Utility functions
std::string invoiceStatusToString(InvoiceStatus status);
void printInvoice(const Invoice& invoice);

#endif
