#ifndef __PRINTER_H__
#define __PRINTER_H__

#include <string>
#include "item.h"

class Printer {
public:
    virtual ~Printer() = default;

    virtual void print(const string& text) = 0;

    void print(const Item& item);
    void printLine(const string& text);
};

#endif // __PRINTER_H__