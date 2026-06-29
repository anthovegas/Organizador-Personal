#ifndef __DATE_H__
#define __DATE_H__

#include <string>
using namespace std;

using I = int;
using B = bool;
using ST = string;

struct Date {
    I day;
    I month;
    I year;

    ST toString() const;
    B isBefore(const Date& other) const;
    I toDayNumber() const;
};

#endif // __DATE_H__