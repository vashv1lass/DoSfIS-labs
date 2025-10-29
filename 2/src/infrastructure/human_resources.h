/**
 * @file infrastructure/human_resources.h
 * @brief Declaration of the HumanResources class and EmployeeInfo struct.
 */

#ifndef INFRASTRUCTURE_HUMAN_RESOURCES_H_
#define INFRASTRUCTURE_HUMAN_RESOURCES_H_

#include <memory>
#include <string>
#include <vector>

// Forward declaration of Employee class in staff namespace
namespace staff {

class Employee;

}  // namespace staff

/**
 * @brief Namespace for all infrastructure-related classes and functions.
 */
namespace infrastructure {

/**
 * @struct EmployeeInfo
 * @brief Holds information about an employee.
 */
struct EmployeeInfo {
  /**
   * @brief Constructor for EmployeeInfo struct.
   * @param name The name of the employee.
   * @param role The role of the employee.
   * @param salary The salary of the employee.
   */
  EmployeeInfo(std::string name, std::string role, int salary);
  
  std::string name;   /// The name of the employee.
  std::string role;   /// The role of the employee.
  int salary;         /// The salary of the employee.
};

/**
 * @class HumanResources
 * @brief Manages the employees within the aquarium.
 */
class HumanResources {
public:
  /**
   * @brief Default constructor for HumanResources class.
   */
  HumanResources() = default;

  /**
   * @brief Hires a new employee.
   * @param employee Unique pointer to the employee to hire.
   */
  void Hire(std::unique_ptr<staff::Employee> employee);

  /**
   * @brief Fires an employee by name.
   * @param name The name of the employee to fire.
   */
  void Fire(const std::string& name);

  /**
   * @brief Finds an employee by name.
   * @param name The name of the employee to find.
   * @return A pointer to the employee, or nullptr if not found.
   */
  staff::Employee* FindEmployee(const std::string& name) noexcept;

  /**
   * @brief Lists all employees with their information.
   * @return A vector of EmployeeInfo structures.
   */
  std::vector<EmployeeInfo> ListEmployees() const;

private:
  std::vector<std::unique_ptr<staff::Employee>> employees_;  /// The collection of employees.
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_HUMAN_RESOURCES_H_