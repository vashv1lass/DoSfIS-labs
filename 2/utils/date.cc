#include "date.h"

Date::Date(int day, int month, int year)
    : day_(day), month_(month), year_(year) {}

void Date::SetDay(int day) noexcept {
    this->day_ = day;
}

void Date::SetMonth(int month) noexcept {
    this->month_ = month;
}

void Date::SetYear(int year) noexcept {
    this->year_ = year;
}

int Date::GetDay() const noexcept {
    return this->day_;
}

int Date::GetMonth() const noexcept {
    return this->month_;
}

int Date::GetYear() const noexcept {
    return this->year_;
}