#include "item.h"
using namespace std;

ID Item::nextId = 1;

Item::Item(const ST& title, Priority priority)
    : id(nextId++), title(title), priority(priority) {}

ID Item::getId() const { return id; }

ST Item::getTitle() const { return title; }

void Item::setTitle(const ST& newTitle) { title = newTitle; }

Priority Item::getPriority() const { return priority; }

void Item::setPriority(Priority p) { priority = p; }

bool Item::operator<(const Item& other) const {
    return priority < other.priority;
}

ostream& operator<<(ostream& out, const Item& item) {
    out << item.toString();
    return out;
}