#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>
#include <ostream>
using namespace std;

using ID = int;
using Priority = int;

using I = int;
using B = bool;
using ST = string;

enum class ItemType { TASK, HABIT, NOTE, GOAL };

class Item {
protected:
    ID id;
    ST title;
    Priority priority;

    static ID nextId;
public:
    Item(const ST& title, Priority priority = 2);

    virtual ~Item() = default;

    ID getId() const;
    ST getTitle() const;
    void setTitle(const ST& newTitle);
    Priority getPriority() const;
    void setPriority(Priority p);

    virtual ItemType getType() const = 0;
    virtual bool isComplete() const = 0;
    virtual ST toString() const = 0;

    bool operator<(const Item& other) const;

    friend ostream& operator<<(ostream& out, const Item& item);

};

#endif //__ITEM_H__