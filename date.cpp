#include "date.h"

S Date::toString() const {
    S d = (day < 10 ? "0" : "") + to_string(day);
    S m = (month < 10 ? "0" : "") + to_string(month);
    return d + "/" + m + "/" + to_string(year);
}

B Date::isBefore(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}