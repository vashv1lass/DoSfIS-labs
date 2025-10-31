/**
 * @file animals/medical/medical.h
 * @brief Declaration of the MedicalRecord and MedicalRecordBook classes.
 */

#ifndef ANIMALS_MEDICAL_MEDICAL_H_
#define ANIMALS_MEDICAL_MEDICAL_H_

#include <chrono>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "animals/medical/diagnosis.h"

// Forward declaration of MedicalDepartment class in infrastructure namespace
namespace infrastructure {

class MedicalDepartment;

}  // namespace infrastructure

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @brief Namespace for medical-related classes and functions.
 */
namespace medical {

/**
 * @class MedicalRecord
 * @brief Represents a single medical record for an animal.
 */
class MedicalRecord {
public:
  /**
   * @brief Constructor for MedicalRecord class.
   * @param diagnosis The diagnosis associated with this record.
   */
  MedicalRecord(Diagnosis diagnosis);

  /**
   * @brief Retrieves the diagnosis associated with this record.
   * @return A const reference to the diagnosis.
   */
  const Diagnosis& GetDiagnosis() const noexcept;
  
  /**
   * @brief Retrieves the creation date of this record.
   * @return The creation date as a system clock time point.
   */
  std::chrono::system_clock::time_point GetCreationDate() const noexcept;

  /**
   * @brief Retrieves the formatted creation date of this record.
   * @return The formatted creation date as a string.
   */
  std::string GetFormattedCreationDate() const;

private:
  Diagnosis diagnosis_;  /// The diagnosis associated with this record.
  std::chrono::system_clock::time_point created_at_;  /// The creation date of this record.
};

/**
 * @class MedicalRecordBook
 * @brief Manages a collection of medical records for an animal.
 */
class MedicalRecordBook {
public:
  /**
   * @brief Constructor for MedicalRecordBook class.
   * @param owner The name of the animal that owns this record book.
   */
  explicit MedicalRecordBook(std::string owner);

  /**
   * @brief Retrieves the last medical record in the record book.
   * @return An optional containing a pointer to the last record, or std::nullopt if no records exist.
   */
  std::optional<const MedicalRecord*> GetLastRecord() const noexcept;

  /**
   * @brief Retrieves all medical records in the record book.
   * @return A vector containing pointers to all medical records.
   */
  std::vector<const MedicalRecord*> GetRecords() const noexcept;

  /**
   * @brief Generates a summary of the medical record book.
   * @return A string containing the summary.
   */
  std::string GetSummary() const;

  /**
   * @brief Retrieves the name of the animal that owns this record book.
   * @return The name of the owner as a string.
   */
  const std::string& GetOwner() const noexcept;

private:
  std::string owner_;  /// The name of the animal that owns this record book.
  std::vector<std::unique_ptr<MedicalRecord>> records_;  /// The collection of medical records.

  /**
   * @brief Adds a medical record to the record book.
   * @param record Unique pointer to the medical record to add.
   * @note This function is private and intended to be used by the MedicalDepartment class.
   */
  void AddRecord(std::unique_ptr<MedicalRecord> record);

  friend class infrastructure::MedicalDepartment;  // Allows MedicalDepartment to access private members.
};

}  // namespace medical
}  // namespace animals

#endif  // ANIMALS_MEDICAL_MEDICAL_H_