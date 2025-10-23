#ifndef ANIMALS_MEDICAL_MEDICAL_H_
#define ANIMALS_MEDICAL_MEDICAL_H_

#include <chrono>
#include <memory>
#include <optional>
#include <string>
#include <sstream>
#include <vector>

#include "animals/medical/diagnosis.h"

namespace animals {
namespace medical {

class MedicalRecord {
 public:
  MedicalRecord(Diagnosis diagnosis);

  const Diagnosis& GetDiagnosis() const noexcept;
  
  std::chrono::system_clock::time_point GetCreationDate() const noexcept;
  std::string GetFormattedCreationDate() const;

 private:
  Diagnosis diagnosis_;
  std::string treatment_plan_;
  std::chrono::system_clock::time_point created_at_;
};

class MedicalRecordBook {
 public:
  explicit MedicalRecordBook(std::string owner);

  void AddRecord(std::unique_ptr<MedicalRecord> record);
  std::optional<const MedicalRecord*> GetLastRecord() const noexcept;
  std::vector<const MedicalRecord*> GetRecords() const noexcept;
  std::string GetSummary() const;

  const std::string& GetOwner() const noexcept;

 private:
  std::string owner_;
  std::vector<std::unique_ptr<MedicalRecord>> records_;
};

}  // namespace medical
}  // namespace animals

#endif  // ANIMALS_MEDICAL_MEDICAL_H_