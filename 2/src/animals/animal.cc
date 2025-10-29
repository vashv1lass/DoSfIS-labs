#include "animals/animal.h"

#include <string>
#include <stdexcept>
#include <memory>

#include "animals/medical/medical.h"

namespace animals {

Animal::Animal(std::string name)
    : name_(std::move(name)), medical_record_book_(nullptr) {
  if (name_.empty()) {
    throw std::invalid_argument("Animal name cannot be empty.");
  }
}

void Animal::AssignMedicalRecordBook(std::shared_ptr<medical::MedicalRecordBook> record_book) {
  if (!record_book) {
    throw std::invalid_argument("Medical record book cannot be null.");
  }
  medical_record_book_ = std::move(record_book);
}

std::shared_ptr<medical::MedicalRecordBook> Animal::GetMedicalRecordBook() const noexcept {
  return medical_record_book_;
}

const std::string& Animal::GetName() const noexcept {
  return name_;
}

}  // namespace animals