#ifndef UTILS_DATE_H_
#define UTILS_DATE_H_

class Date {
public:
    Date(int, int, int);

    void SetDay(int);
    void SetMonth(int);
    void SetYear(int);

    int GetDay() const noexcept;
    int GetMonth() const noexcept;
    int GetYear() const noexcept;
private:
    int day_;
    int month_;
    int year_;
};

#endif // UTILS_DATE_H_