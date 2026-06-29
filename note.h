#ifndef __NOTE_H__
#define __NOTE_H__

#include "item.h"

class Note : public Item {
private:
    ST content;

public:
    Note(const ST& title, const ST& content = "", Priority priority = 3);

    ST getContent() const;
    void setContent(const ST& newContent);
    void appendContent(const ST& extra);

    ItemType getType() const override;
    B isComplete() const override;
    ST toString() const override;
};

#endif // __NOTE_H__