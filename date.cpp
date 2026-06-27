#include "date.h"

namespace {
    B isLeapYear(I year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
}

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

I Date::toDayNumber() const {
    static const I daysinMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    I total = year * 365 + year / 4 - year / 100 + year / 400;

    for (auto i = 0; i < month - 1; i++) {
        total += daysinMonth[i];
        if (i == 1 && isLeapYear(year)) total++;
    }

    total += day;
    return total;
}