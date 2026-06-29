#include "note.h"

Note::Note(const ST& title, const ST& content, Priority priority)
    : Item(title, priority), content(content) {}

ST Note::getContent() const { return content; }

void Note::setContent(const ST& newContent) { content = newContent; }

void Note::appendContent(const ST& extra) {
    content += "\n" + extra;
}

ItemType Note::getType() const { return ItemType::NOTE; }

B Note::isComplete() const {
    return true;
}

ST Note::toString() const {
    return "[NOTA]" + title + "\n " + content + "\n";
}