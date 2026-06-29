#ifndef __GOAL_H__
#define __GOAL_H__

#include "item.h"
#include "date.h"
#include <string>

class Goal : public Item {
private:
    I targetValue;
    I currentValue;
    ST  unit;
    Date deadline;

public:
    Goal(const ST& title, I targetValue, const ST& unit,
         Date deadline, Priority priority = 2);

    void addProgress(I amount);
    I getProgress() const;
    I getTarget() const;
    Date getDeadline() const;
    
    B isOverdue(const Date& today) const;

    ItemType getType() const override;
    B isComplete() const override;
    ST toString() const override;
};

#endif // __GOAL_H__