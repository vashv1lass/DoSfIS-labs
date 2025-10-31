/**
 * @file staff/veterinarian.h
 * @brief Declaration of the Veterinarian class.
 */

#ifndef STAFF_VETERINARIAN_H_
#define STAFF_VETERINARIAN_H_

#include "animals/animal.h"
#include "animals/medical/diagnosis.h"
#include "animals/medical/medical.h"
#include "staff/employee.h"

/**
 * @brief Namespace for all staff-related classes and functions.
 */
namespace staff {

/**
 * @class Veterinarian
 * @brief Derived class representing a veterinarian, inheriting from Employee.
 */
class Veterinarian : public Employee {
public:
  /**
   * @brief Constructor for Veterinarian class.
   * @param name The name of the veterinarian.
   * @param salary The salary of the veterinarian.
   */
  Veterinarian(std::string name, double salary);

  /**
   * @brief Retrieves the role of the veterinarian.
   * @return The role as a string ("Veterinarian").
   * @note Overrides the GetRole function from the Employee base class.
   */
  std::string GetRole() const noexcept override;
  
  /**
   * @brief Performs a diagnosis on an animal and records it in the medical record book.
   * @param animal Reference to the animal to diagnose.
   * @param record_book Reference to the medical record book to update.
   * @param diagnosis The diagnosis to record.
   * @note This function creates a new medical record with the given diagnosis.
   */
  void Diagnose(animals::Animal& animal,
                infrastructure::MedicalDepartment& department,
                animals::medical::Diagnosis diagnosis);
};

}  // namespace staff

#endif  // STAFF_VETERINARIAN_H_