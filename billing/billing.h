#ifndef BILLING_H
#define BILLING_H

#include "invoice.h"
#include <string>

class BillingService {
public:
    Invoice generateInvoice(
        const std::string& customerId,
        double baseAmount,
        double taxRate,
        double discount
    );

    void markAsPaid(Invoice& invoice);
};

#endif
