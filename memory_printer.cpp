#include "memory_printer.h"

void MemoryPrinter::print(const string& text) {
    buffer += text;
}

string MemoryPrinter::getContent() const {
    return buffer;
}

void MemoryPrinter::clearConcent() {
    buffer.clear();
}