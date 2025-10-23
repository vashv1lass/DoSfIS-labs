#ifndef STAFF_EMPLOYEE_H_
#define STAFF_EMPLOYEE_H_

#include <string>

namespace staff {

class Employee {
 public:
  explicit Employee(std::string name, double salary);
  virtual ~Employee() = default;

  const std::string& GetName() const noexcept;
  double GetSalary() const noexcept;
  virtual std::string GetRole() const noexcept = 0;

 protected:
  std::string name_;
  double salary_;
};

}  // namespace staff

#endif  // STAFF_EMPLOYEE_H_