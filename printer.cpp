#include "printer.h"

void Printer::print(const Item& item) {
    print(item.toString());
}

void Printer::printLine(const ST& text) {
    print(text + "\n");
}