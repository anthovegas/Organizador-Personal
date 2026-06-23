#include "file_printer.h"
#include <stdexcept>/////////

FilePrinter::FilePrinter(const string& filename) {
    file.open(filename, ios::app);
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + filename); //////////
    }
}

FilePrinter::~FilePrinter() {
    file.close();
}

void FilePrinter::print(const string& text) {
    file << text;
}