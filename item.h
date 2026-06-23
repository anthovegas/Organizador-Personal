#ifndef __ITEM_h__
#define __ITEM_H__

#include <string>
#include <ostream>
using namespace std;

using ID = int;
using Priority = int;

using I = int;
using B = bool;
using S = string;

enum class ItemType { TASK, HABIT, NOTE, GOAL };

class Item {
protected:
    ID id;
    string title;
    Priority priority;

    static ID nextId;
public:
    Item(const string& title, Priority priority = 2);

    virtual ~Item() = default;

    ID getId() const;
    string getTitle() const;
    void setTitle(const string& newTitle);
    Priority getPriority() const;
    void setPriority(Priority p);

    virtual ItemType getType() const = 0;
    virtual bool isComplete() const = 0;
    virtual string toString() const = 0;

    bool operator<(const Item& other) const;

    friend ostream& operator<<(ostream& out, const Item& item);

};

#endif //__ITEM_H__