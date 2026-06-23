#include "printer.h"

void Printer::print(const Item& item) {
    print(item.toString());
}

void Printer::printLine(const string& text) {
    print(text + "\n");
}