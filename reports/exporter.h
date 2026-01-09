#ifndef EXPORTER_H
#define EXPORTER_H

#include "../billing/invoice.h"
#include <vector>
#include <string>

/*
 * ReportExporter
 * ----------------
 * Responsible only for exporting reports
 * (CSV now, PDF/JSON can be added later)
 */
class ReportExporter {
public:
    // Export invoice data to CSV file
    static void exportToCSV(
        const std::vector<Invoice>& invoices,
        const std::string& filename
    );
};

#endif
