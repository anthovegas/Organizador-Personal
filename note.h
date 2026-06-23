#ifndef __NOTE_H__
#define __NOTE_H__

#include "item.h"

class Note : public Item {
private:
    string content;

public:
    Note(const string& title, const string& content = "", Priority priority = 3);

    string getContent() const;
    void setContent(const string& newContent);
    void appendContent(const string& extra);

    ItemType getType() const override;
    B isComplete() const override;
    string toString() const override;
};

#endif // __NOTE_H__