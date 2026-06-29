#include "habit.h"

Habit::Habit(const ST& title, Priority priority)
    : Item (title, priority), currentStreak(0), bestStreak(0),
      lastCompleted({0, 0, 0}), doneToday(false) {}

void Habit::markDoneToday(const Date& today) {
    if (doneToday) return;

    I gap = today.toDayNumber() - lastCompleted.toDayNumber();

    if (currentStreak > 0 && gap == 1) {
        currentStreak++;
    } else {
        currentStreak = 1;
    }

    if (currentStreak > bestStreak) {
        bestStreak = currentStreak;
    }

    lastCompleted = today;
    doneToday = true;
}
void Habit::resetDay() {
    doneToday = false;
}

I Habit::getCurrentStreak() const { return currentStreak; }

I Habit::getBestStreak() const { return bestStreak; }

Date Habit::getLastCompleted() const { return lastCompleted; }

ItemType Habit::getType() const { return ItemType::HABIT; }

B Habit::isComplete() const { return doneToday; }

ST Habit::toString() const {
    ST status = doneToday ? "[HECHO HOY]" : "[PENDIENTE HOY]";
    return status + " " + title +
           " - racha actual: " + to_string(currentStreak) + " dias" +
           " (mejor racha: " + to_string(bestStreak) + ")\n";
}