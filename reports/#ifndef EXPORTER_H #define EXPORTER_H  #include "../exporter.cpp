#include "exporter.h"
#include <fstream>
#include <iostream>

void ReportExporter::exportToCSV(
    const std::vector<Invoice>& invoices,
    const std::string& filename
) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "Failed to create report file\n";
        return;
    }

    // CSV Header
    file << "InvoiceID,CustomerID,BaseAmount,TaxAmount,Discount,TotalAmount,Status\n";

    for (const auto& inv : invoices) {
        file << inv.invoiceId << ","
             << inv.customerId << ","
             << inv.baseAmount << ","
             << inv.taxAmount << ","
             << inv.discountAmount << ","
             << inv.totalAmount << ",";

        switch (inv.status) {
            case InvoiceStatus::PENDING:
                file << "PENDING";
                break;
            case InvoiceStatus::PAID:
                file << "PAID";
                break;
            case InvoiceStatus::CANCELLED:
                file << "CANCELLED";
                break;
        }
        file << "\n";
    }

    file.close();
    std::cout << "Report exported to " << filename << std::endl;
}
