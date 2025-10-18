#include "employee.h"

#include <string>
#include <stdexcept>

#include "utils/date.h"

Employee::Employee(const std::string &name, const Date &hire_date, double salary)
        : name_(name), hire_date_(hire_date), salary_(salary) {}

std::string Employee::GetName() const noexcept {
    return name_;
}

Date Employee::GetHireDate() const noexcept {
    return hire_date_;
}

void Employee::SetSalary(double salary) {
    if (salary < 0) {
        throw std::out_of_range("Salary must be non-negative.");
    }
    salary_ = salary;
}

double Employee::GetSalary() const noexcept {
    return salary_;
}