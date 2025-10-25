#ifndef INFRASTRUCTURE_HUMAN_RESOURCES_H_
#define INFRASTRUCTURE_HUMAN_RESOURCES_H_

#include <memory>
#include <string>
#include <vector>

#include "staff/employee.h"

namespace infrastructure {

struct EmployeeInfo {
  EmployeeInfo(std::string name, std::string role, int salary);
  
  std::string name;
  std::string role;
  int salary;
};

class HumanResources {
public:
  HumanResources() = default;

  void Hire(std::unique_ptr<staff::Employee> employee);
  void Fire(const std::string& name);

  staff::Employee* FindEmployee(const std::string& name) noexcept;
  std::vector<EmployeeInfo> ListEmployees() const;

private:
  std::vector<std::unique_ptr<staff::Employee>> employees_;
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_HUMAN_RESOURCES_H_