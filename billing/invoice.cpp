#include "invoice.h"
#include <iostream>

// Helper function to convert InvoiceStatus to readable string
std::string invoiceStatusToString(InvoiceStatus status) {
    switch (status) {
        case InvoiceStatus::PENDING:
            return "PENDING";
        case InvoiceStatus::PAID:
            return "PAID";
        case InvoiceStatus::CANCELLED:
            return "CANCELLED";
        default:
            return "UNKNOWN";
    }
}

// Print invoice details (utility function)
void printInvoice(const Invoice& invoice) {
    std::cout << "------------------------------\n";
    std::cout << "Invoice ID     : " << invoice.invoiceId << "\n";
    std::cout << "Customer ID    : " << invoice.customerId << "\n";
    std::cout << "Base Amount    : ₹" << invoice.baseAmount << "\n";
    std::cout << "Tax Amount     : ₹" << invoice.taxAmount << "\n";
    std::cout << "Discount       : ₹" << invoice.discountAmount << "\n";
    std::cout << "Total Amount   : ₹" << invoice.totalAmount << "\n";
    std::cout << "Status         : "
              << invoiceStatusToString(invoice.status) << "\n";
    std::cout << "------------------------------\n";
}
