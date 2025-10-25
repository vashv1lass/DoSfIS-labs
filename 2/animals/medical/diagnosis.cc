#include "animals/medical/diagnosis.h"

namespace animals {
namespace medical {

Diagnosis::Diagnosis(DiagnosisType type) : type_(type) {}

DiagnosisType Diagnosis::GetType() const noexcept { return type_; }

std::string Diagnosis::GetDescription() const {
  switch (type_) {
    case DiagnosisType::kHealthy:
      return "The animal is healthy.";
    case DiagnosisType::kCold:
      return "Signs of a mild cold.";
    case DiagnosisType::kInjury:
      return "Detected a minor injury.";
    case DiagnosisType::kInfection:
      return "Possible bacterial infection.";
    default:
      throw utils::exceptions::UnknownTypeError("Diagnosis type is unknown.");
  }
}

std::string Diagnosis::ToString() const {
  switch (type_) {
    case DiagnosisType::kHealthy:
      return "Healthy";
    case DiagnosisType::kCold:
      return "Cold";
    case DiagnosisType::kInjury:
      return "Injurys";
    case DiagnosisType::kInfection:
      return "Infection";
  }
}

}  // namespace medical
}  // namespace animals