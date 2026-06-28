#ifndef __CALENDAR_H__
#define __CALENDAR_H__

#include "cmatrix.h"
#include "item.h"
#include <string> ////////////
using namespace std;

enum class Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
using Slot = int;

using I = int;
using B = bool;

const I DAYS_IN_WEEK = 7;
const I SLOTS_PER_DAY = 12;

class Calendar {
private:
    CMatrix<Item*> grid;

    I dayToIndex(Day day) const;
    string dayName(Day day) const;
    string slotLabel(I slot) const;

public:
    Calendar();

    B scheduleItem(Day day, I slot, Item* item);
    B removeItem(Day day, I slot);
    Item* getItem(Day day, I slot) const;
    B isFree(Day day, I slot) const;

    I countItemsInDay(Day day) const;
    string toString() const;
};

#endif // __CALENDAR_H__