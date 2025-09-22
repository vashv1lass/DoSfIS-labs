#include "date.h"

#include <stdexcept>

inline static bool year_is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

inline static bool thirty_one_day_month(int month) {
    return (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12);
}

inline static void check_date_validity(int day, int month, int year) {
    if (!(1601 <= year && year <= 2025)) {
        throw std::invalid_argument(
            "Invalid year value. Year value must not "
            "be less than 1601 and greater than 2025"
        );
    }

    if (!(1 <= month && month <= 12)) {
        throw std::invalid_argument("Invalid month value");
    }

    if (thirty_one_day_month(month)) {
        if (!(1 <= day && day <= 31)) {
            throw std::invalid_argument("Invalid day value");
        }
    } else if (month != 2) {
        if (!(1 <= day && day <= 30)) {
            throw std::invalid_argument("Invalid day value");
        }
    } else { // if month == 2
        if (!year_is_leap(year)) {
            if (!(1 <= day && day <= 28)) {
                throw std::invalid_argument("Invalid day value");
            }
        } else {
            if (!(1 <= day && day <= 29)) {
                throw std::invalid_argument("Invalid day value");
            }
        }
    }
}

Date::Date(int day, int month, int year)
    : day_(day), month_(month), year_(year) {
    check_date_validity(day, month, year);
}

void Date::SetDay(int day) {
    check_date_validity(day, month_, year_);
    day_ = day;
}

void Date::SetMonth(int month) {
    check_date_validity(day_, month, year_);
    month_ = month;
}

void Date::SetYear(int year) {
    check_date_validity(day_, month_, year);
    year_ = year;
}

int Date::GetDay() const noexcept {
    return day_;
}

int Date::GetMonth() const noexcept {
    return month_;
}

int Date::GetYear() const noexcept {
    return year_;
}