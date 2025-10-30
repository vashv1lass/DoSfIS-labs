#include "infrastructure/human_resources.h"

#include <algorithm>
#include <stdexcept>

#include "staff/employee.h"
#include "utils/exceptions/not_found_errors.h"

namespace infrastructure {

EmployeeInfo::EmployeeInfo(std::string name, std::string role, int salary)
    : name(std::move(name)), role(std::move(role)), salary(salary) {}

void HumanResources::Hire(std::unique_ptr<staff::Employee> employee) {
  if (!employee) {
    throw std::invalid_argument("Employee cannot be null.");
  }
  employees_.push_back(std::move(employee));
}

void HumanResources::Fire(const std::string& name) {
  auto it = std::remove_if(employees_.begin(), employees_.end(),
                           [&](const auto& e) { return e->GetName() == name; });

  if (it == employees_.end()) {
    throw utils::exceptions::EmployeeNotFoundError("Employee not found.");
  }

  employees_.erase(it, employees_.end());
}

staff::Employee* HumanResources::FindEmployee(const std::string& name) noexcept {
  for (auto& e : employees_) {
    if (e->GetName() == name) {
      return e.get();
    }
  }
  return nullptr;
}

std::vector<EmployeeInfo> HumanResources::ListEmployees() const {
  std::vector<EmployeeInfo> result;
  result.reserve(employees_.size());
  for (const auto& e : employees_) {
    result.push_back(EmployeeInfo(e->GetName(), e->GetRole(), e->GetSalary()));
  }
  return result;
}

}  // namespace infrastructure