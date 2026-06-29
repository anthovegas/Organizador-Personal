#include "calendar.h"

Calendar::Calendar() : grid(DAYS_IN_WEEK, SLOTS_PER_DAY, nullptr) {}

I Calendar::dayToIndex(Day day) const {
    return static_cast<int>(day); /////////////
}

ST Calendar::dayName(Day day) const {
    switch (day) {
        case Day::MONDAY: return "Lunes";
        case Day::TUESDAY: return "Martes";
        case Day::WEDNESDAY: return "Miercoles";
        case Day::THURSDAY: return "Jueves";
        case Day::FRIDAY: return "Viernes";
        case Day::SATURDAY: return "Sabado";
        case Day::SUNDAY: return "Domingo";
    }
    return "?";
}

ST Calendar::slotLabel(I slot) const {
    I hour = 8 + slot;
    return to_string(hour) + ":00";
}

B Calendar::scheduleItem(Day day, I slot, Item* item) {
    I row = dayToIndex(day);
    if (grid.at(row, slot) != nullptr) {
        return false;
    }
    grid.at(row, slot) = item;
    return true;
}

B Calendar::removeItem(Day day, I slot) {
    I row = dayToIndex(day);
    if (grid.at(row, slot) == nullptr) return false;
    grid.at(row, slot) = nullptr;
    return true;
}

Item* Calendar::getItem(Day day, I slot) const {
    return grid.at(dayToIndex(day), slot);
}

B Calendar::isFree(Day day, I slot) const {
    return grid.at(dayToIndex(day), slot) == nullptr;
}

I Calendar::countItemsInDay(Day day) const {
    I row = dayToIndex(day);
    I count = 0;
    for (auto col = 0; col < grid.cols(); col++) {
        if (grid.at(row, col) != nullptr) count++;
    }
    return count;
}

ST Calendar::toString() const {
    ST result = "";
    for (auto row = 0; row < grid.rows(); row++) {
        result += dayName(static_cast<Day>(row)) + ":\n"; ///////////
        for (auto col = 0; col < grid.cols(); col++) {
            Item* it = grid.at(row, col);
            if (it != nullptr) {
                result += " " + slotLabel(col) + " - " + it->toString();
            }
        }
        result += "\n";
    }
    return result;
}