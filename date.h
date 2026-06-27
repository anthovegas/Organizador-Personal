#ifndef __DATE_H__
#define __DATE_H__

#include <string>
using I = int;
using B = bool;
using S = string;
using namespace std;

struct Date {
    I day;
    I month;
    I year;

    S toString() const;
    B isBefore(const Date& other) const;
};

#endif // __DATE_H__