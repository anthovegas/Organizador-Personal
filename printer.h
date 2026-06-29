#ifndef __PRINTER_H__
#define __PRINTER_H__

#include <string>
#include "item.h"

class Printer {
public:
    virtual ~Printer() = default;

    virtual void print(const ST& text) = 0;

    void print(const Item& item);
    void printLine(const ST& text);
};

#endif // __PRINTER_H__