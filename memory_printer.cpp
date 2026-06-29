#include "memory_printer.h"

void MemoryPrinter::print(const ST& text) {
    buffer += text;
}

ST MemoryPrinter::getContent() const {
    return buffer;
}

void MemoryPrinter::clearConcent() {
    buffer.clear();
}