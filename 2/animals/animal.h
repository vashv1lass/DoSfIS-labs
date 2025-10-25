#ifndef ANIMALS_ANIMAL_H_
#define ANIMALS_ANIMAL_H_

#include <memory>
#include <string>
#include <stdexcept>

#include "animals/medical/medical.h"
#include "staff/diver_feeder.h"

namespace animals {

class Animal {
public:
  explicit Animal(std::string name);
  virtual ~Animal() noexcept = default;

  virtual void Move() const noexcept = 0;
  virtual std::string GetSpecies() const noexcept = 0;

  void AssignMedicalRecordBook(std::shared_ptr<medical::MedicalRecordBook> record_book);
  std::shared_ptr<medical::MedicalRecordBook> GetMedicalRecordBook() const noexcept;

  const std::string& GetName() const noexcept;

protected:
  std::string name_;
  std::shared_ptr<medical::MedicalRecordBook> medical_record_book_;

  virtual void Eat() const noexcept = 0;

  friend class staff::DiverFeeder;
};

}  // namespace animals

#endif  // ANIMALS_ANIMAL_H_