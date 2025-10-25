#include "infrastructure/medical_department.h"

#include <stdexcept>

namespace infrastructure {

void MedicalDepartment::RegisterBook(std::string animal_name,
                                     std::unique_ptr<animals::medical::MedicalRecordBook> record_book) {
  if (!record_book) {
    throw std::invalid_argument("Medical record book cannot be null.");
  }
  record_books_.emplace(std::move(animal_name), std::move(record_book));
}

void MedicalDepartment::AddRecord(const std::string& animal_name,
                                  animals::medical::Diagnosis diagnosis) {
  auto it = record_books_.find(animal_name);
  if (it == record_books_.end()) {
    throw utils::exceptions::NotFoundError("No record book for " + animal_name + ".");
  }

  it->second->AddRecord(std::make_unique<animals::medical::MedicalRecord>(diagnosis));
}

std::string MedicalDepartment::GetSummary(const std::string& animal_name) const {
  auto it = record_books_.find(animal_name);
  if (it == record_books_.end()) {
    throw utils::exceptions::NotFoundError("No record book for " + animal_name + ".");
  }

  return it->second->GetSummary();
}

}  // namespace infrastructure