/**
 * @file infrastructure/medical_department.h
 * @brief Declaration of the MedicalDepartment class.
 */

#ifndef INFRASTRUCTURE_MEDICAL_DEPARTMENT_H_
#define INFRASTRUCTURE_MEDICAL_DEPARTMENT_H_

#include <memory>
#include <string>
#include <unordered_map>

#include "animals/medical/diagnosis.h"
#include "animals/medical/medical.h"

/**
 * @brief Namespace for all infrastructure-related classes and functions.
 */
namespace infrastructure {

/**
 * @class MedicalDepartment
 * @brief Manages the medical records and health status of animals in the aquarium.
 */
class MedicalDepartment {
public:
  /**
   * @brief Default constructor for MedicalDepartment class.
   */
  MedicalDepartment() = default;

  /**
   * @brief Registers a medical record book for an animal.
   * @param animal_name The name of the animal associated with the book.
   * @param book Unique pointer to the medical record book to register.
   */
  void RegisterBook(std::string animal_name, std::unique_ptr<animals::medical::MedicalRecordBook> book);
  
  /**
   * @brief Adds a medical record to an animal's record book.
   * @param animal_name The name of the animal to add the record for.
   * @param diagnosis The diagnosis to add to the record.
   */
  void AddRecord(const std::string& animal_name, animals::medical::Diagnosis diagnosis);
  
  /**
   * @brief Retrieves the medical summary for an animal.
   * @param animal_name The name of the animal to get the summary for.
   * @return A string containing the medical summary.
   */
  std::string GetSummary(const std::string& animal_name) const;
  
private:
  std::unordered_map<std::string, std::unique_ptr<animals::medical::MedicalRecordBook>> record_books_;  /// Map of medical record books by animal name.
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_MEDICAL_DEPARTMENT_H_