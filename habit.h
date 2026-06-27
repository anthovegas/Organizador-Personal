#ifndef __HABIT_H__
#define __HABIT_H__

#include "item.h"
#include "date.h"

class Habit : public Item {
private:
    I currentStreak;
    I bestStreak;
    Date lastCompleted;
    B doneToday;

public:
    Habit(const S& title, Priority priority = 2);

    void markDoneToday(const Date& today);
    void resetDay();

    I getCurrentStreak() const;
    I getBestStreak() const;
    Date getLastCompleted() const;

    ItemType getType() const override;
    B isComplete() const override;
    S toString() const override;
};

#endif // __HABIT_H__