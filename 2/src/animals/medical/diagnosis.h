/**
 * @file animals/medical/diagnosis.h
 * @brief Declaration of the Diagnosis class and DiagnosisType enum.
 */

#ifndef ANIMALS_MEDICAL_DIAGNOSIS_H_
#define ANIMALS_MEDICAL_DIAGNOSIS_H_

#include <string>

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @brief Namespace for medical-related classes and functions.
 */
namespace medical {

/**
 * @enum DiagnosisType
 * @brief Enumerates the possible types of medical diagnoses.
 */
enum class DiagnosisType {
  kHealthy,    /// Indicates the animal is healthy.
  kCold,       /// Indicates the animal has a cold.
  kInjury,     /// Indicates the animal has an injury.
  kInfection   /// Indicates the animal has an infection.
};

/**
 * @class Diagnosis
 * @brief Represents a medical diagnosis for an animal.
 */
class Diagnosis {
public:
  /**
   * @brief Constructor for Diagnosis class.
   * @param type The type of the diagnosis.
   */
  explicit Diagnosis(DiagnosisType type);

  /**
   * @brief Retrieves the type of the diagnosis.
   * @return The type of the diagnosis.
   */
  DiagnosisType GetType() const noexcept;

  /**
   * @brief Retrieves the description of the diagnosis.
   * @return The description of the diagnosis as a string.
   * @throws utils::exceptions::UnknownDiagnosisTypeError if the diagnosis type is unknown.
   */
  std::string GetDescription() const;

  /**
   * @brief Converts the diagnosis to its string representation.
   * @return The string representation of the diagnosis.
   */
  std::string ToString() const;

private:
  DiagnosisType type_;  /// The type of the diagnosis.
};

}  // namespace medical
}  // namespace animals

#endif  // ANIMALS_MEDICAL_DIAGNOSIS_H_