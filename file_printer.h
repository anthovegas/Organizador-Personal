#ifndef __FILE_PRINTER_H__
#define __FILE_PRINTER_H__

#include "printer.h"
#include <fstream>
#include <string>

class FilePrinter : public Printer {
private:
    ofstream file;

public:
    explicit FilePrinter(const string& filename); //////////
    ~FilePrinter() override;

    void print(const string& text) override;
};

#endif //__FILE_PRINTER_H__