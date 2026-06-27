#include "goal.h"

Goal::Goal(const S& title, I targetValue, const S& unit,
         Date deadline, Priority priority)
    : Item(title, priority), targetValue(targetValue), currentValue(0),
        unit(unit), deadline(deadline) {}

void Goal::addProgress(I amount) {
    currentValue += amount;
    if (currentValue > targetValue) {
        currentValue = targetValue;
    }
}
I Goal::getProgress() const { return currentValue; }

I Goal::getTarget() const { return targetValue; }

Date Goal:: getDeadline() const { return deadline; }
    
B Goal::isOverdue(const Date& today) const {
    return !isComplete() && deadline.isBefore(today);
}

ItemType Goal::getType() const { return ItemType::GOAL; }

B Goal::isComplete() const { return currentValue >= targetValue; }

S Goal::toString() const {
    S status = isComplete() ? "[CUMPLIDA]" : "[EN PROGRESO]";
    return status + " " + title + ": " + to_string(currentValue) + "/" +
            to_string(targetValue) + " " + unit + 
            " (plazo: " + deadline.toString() + ")\n";
}