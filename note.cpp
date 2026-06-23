#include "note.h"

Note::Note(const string& title, const string& content, Priority priority)
    : Item(title, priority), content(content) {}

std::string Note::getContent() const { return content; }

void Note::setContent(const string& newContent) { content = newContent; }

void Note::appendContent(const string& extra) {
    content += "\n" + extra;
}

ItemType Note::getType() const { return ItemType::NOTE; }

B Note::isComplete() const {
    return true;
}

string Note::toString() const {
    return "[NOTA]" + title + "\n " + content + "\n";
}