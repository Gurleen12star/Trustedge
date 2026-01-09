#include "billing.h"
#include <iostream>

Invoice BillingService::generateInvoice(
    const std::string& customerId,
    double baseAmount,
    double taxRate,
    double discount
) {
    Invoice invoice;

    invoice.invoiceId = "INV_" + customerId;
    invoice.customerId = customerId;

    invoice.baseAmount = baseAmount;
    invoice.taxAmount = baseAmount * taxRate;
    invoice.discountAmount = discount;

    invoice.totalAmount =
        baseAmount + invoice.taxAmount - invoice.discountAmount;

    invoice.status = InvoiceStatus::PENDING;

    std::cout << "Invoice generated for customer: "
              << customerId << std::endl;

    return invoice;
}

void BillingService::markAsPaid(Invoice& invoice) {
    invoice.status = InvoiceStatus::PAID;
    std::cout << "Invoice marked as PAID: "
              << invoice.invoiceId << std::endl;
}
