#ifndef __MEMORY_PRINTER_H__
#define __MEMORY_PRINTER_H__

#include "printer.h"
#include <string>

class MemoryPrinter : public Printer {
private:
    ST buffer;

public:
    using Printer::print;
    void print(const ST& text) override;
    ST getContent() const;
    void clearConcent();
};

#endif // __MEMORY_PRINTER_H__