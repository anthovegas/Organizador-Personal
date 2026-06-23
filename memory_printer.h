#ifndef __MEMORY_PRINTER_H__
#define __MEMORY_PRINTER_H__

#include "printer.h"
#include <string>

class MemoryPrinter : public Printer {
private:
    string buffer;

public:
    void print(const string& text) override;
    string getContent() const;
    void clearConcent();
};

#endif // __MEMORY_PRINTER_H__