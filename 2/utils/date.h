#ifndef UTILS_DATE_H_
#define UTILS_DATE_H_

class Date {
public:
    Date(int day = -1, int month = -1, int year = -1);

    Date(const Date &) = default;
    Date &operator=(const Date &) = default;

    Date(Date &&) noexcept = default;
    Date &operator=(Date &&) noexcept = default;

    ~Date() = default;

    void SetDay(int) noexcept;
    void SetMonth(int) noexcept;
    void SetYear(int) noexcept;

    int GetDay() const noexcept;
    int GetMonth() const noexcept;
    int GetYear() const noexcept;
private:
    int day_;
    int month_;
    int year_;
};

#endif // UTILS_DATE_H_