#ifndef EMPLOYEES_EMPLOYEE_H_
#define EMPLOYEES_EMPLOYEE_H_

#include <string>

#include "utils/date.h"

class Employee {
public:
    Employee(const std::string &, const Date &, double);

    virtual ~Employee() = default;

    std::string GetName() const noexcept;
    
    Date GetHireDate() const noexcept;

    void SetSalary(double);
    double GetSalary() const;
protected:
    std::string name_;
    Date hire_date_;
    double salary_;
};

#endif // EMPLOYEES_EMPLOYEE_H_