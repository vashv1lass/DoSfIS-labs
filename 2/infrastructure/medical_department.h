#ifndef INFRASTRUCTURE_MEDICAL_DEPARTMENT_H_
#define INFRASTRUCTURE_MEDICAL_DEPARTMENT_H_

#include <memory>
#include <string>
#include <unordered_map>

#include "animals/medical/diagnosis.h"

namespace animals {
namespace medical {
  
class MedicalRecordBook;

}  // namespace medical
}  // namespace animals

namespace infrastructure {

class MedicalDepartment {
public:
  MedicalDepartment() = default;

  void RegisterBook(std::string animal_name, std::unique_ptr<animals::medical::MedicalRecordBook> book);
  
  void AddRecord(const std::string& animal_name, animals::medical::Diagnosis diagnosis);
  
  std::string GetSummary(const std::string& animal_name) const;
  
private:
  std::unordered_map<std::string, std::unique_ptr<animals::medical::MedicalRecordBook>> record_books_;
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_MEDICAL_DEPARTMENT_H_