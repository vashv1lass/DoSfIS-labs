/**
 * @file staff/employee.h
 * @brief Declaration of the Employee class.
 */

#ifndef STAFF_EMPLOYEE_H_
#define STAFF_EMPLOYEE_H_

#include <string>

/**
 * @brief Namespace for all staff-related classes and functions.
 */
namespace staff {

/**
 * @class Employee
 * @brief Abstract base class representing a generic employee.
 */
class Employee {
public:
  /**
   * @brief Constructor for Employee class.
   * @param name The name of the employee.
   * @param salary The salary of the employee.
   */
  explicit Employee(std::string name, double salary);

  /**
   * @brief Virtual destructor for Employee class.
   */
  virtual ~Employee() = default;

  /**
   * @brief Retrieves the name of the employee.
   * @return The name of the employee as a string.
   */
  const std::string& GetName() const noexcept;

  /**
   * @brief Retrieves the salary of the employee.
   * @return The salary of the employee.
   */
  double GetSalary() const noexcept;

  /**
   * @brief Pure virtual function to get the role of the employee.
   * @return The role of the employee as a string.
   */
  virtual std::string GetRole() const noexcept = 0;

protected:
  std::string name_;  /// The name of the employee.
  double salary_;     /// The salary of the employee.
};

}  // namespace staff

#endif  // STAFF_EMPLOYEE_H_