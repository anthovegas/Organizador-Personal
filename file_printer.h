#ifndef __FILE_PRINTER_H__
#define __FILE_PRINTER_H__

#include "printer.h"
#include <fstream>
#include <string>

class FilePrinter : public Printer {
private:
    ofstream file;

public:
    using Printer::print;
    explicit FilePrinter(const ST& filename); //////////
    ~FilePrinter() override;

    void print(const ST& text) override;
};

#endif //__FILE_PRINTER_H__