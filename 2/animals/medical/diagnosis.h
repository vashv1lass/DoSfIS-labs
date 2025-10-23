#ifndef ANIMALS_MEDICAL_DIAGNOSIS_H_
#define ANIMALS_MEDICAL_DIAGNOSIS_H_

#include <string>
#include <stdexcept>

namespace animals {
namespace medical {

enum class DiagnosisType {
  kHealthy,
  kCold,
  kInjury,
  kInfection
};

class Diagnosis {
 public:
  explicit Diagnosis(DiagnosisType type);

  DiagnosisType GetType() const noexcept;
  std::string GetDescription() const;

  std::string ToString() const;

 private:
  DiagnosisType type_;
};

}  // namespace medical
}  // namespace animals

#endif  // ANIMALS_MEDICAL_DIAGNOSIS_H_