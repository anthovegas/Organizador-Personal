#ifndef __CONSOLE_PRINTER_H__
#define __CONSOLE_PRINTER_H__

#include "printer.h"

class ConsolePrinter : public Printer {
public:
    using Printer::print;
    void print(const ST& text) override;
};

#endif // __CONSOLE_PRINTER_H__