#include "staff/employee.h"

#include <string>
#include <stdexcept>

namespace staff {

Employee::Employee(std::string name, double salary)
    : name_(std::move(name)), salary_(salary) {
  if (name_.empty()) {
    throw std::invalid_argument("Employee name cannot be empty.");
  }
  if (salary_ <= 0.0) {
    throw std::out_of_range("Salary must be positive.");
  }
}

const std::string& Employee::GetName() const noexcept { return name_; }

double Employee::GetSalary() const noexcept { return salary_; }

}  // namespace staff