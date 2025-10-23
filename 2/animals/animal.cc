#include "animals/animal.h"

#include <string>
#include <stdexcept>
#include <memory>

#include "animals/medical/medical.h"

namespace animals {

Animal::Animal(std::string name) : name_(std::move(name)) {
  if (name_.empty()) {
    throw std::invalid_argument("Animal name cannot be empty.");
  }
}

void Animal::AssignMedicalRecordBook(std::shared_ptr<medical::MedicalRecordBook> card) {
  if (!card) {
    throw std::invalid_argument("MedicalRecordBook cannot be null.");
  }
  medical_record_book_ = std::move(card);
}

std::shared_ptr<medical::MedicalRecordBook> Animal::GetMedicalRecordBook() const noexcept {
  return medical_record_book_;
}

const std::string& Animal::GetName() const noexcept {
  return name_;
}

}  // namespace animals