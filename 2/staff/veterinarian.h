#ifndef STAFF_VETERINARIAN_H_
#define STAFF_VETERINARIAN_H_

#include "staff/employee.h"
#include "animals/medical/diagnosis.h"

#include <iostream>

namespace animals {

class Animal;

namespace medical {

class MedicalRecordBook;

}  // namespace medical

}  // namespace animals

namespace staff {

class Veterinarian : public Employee {
public:
  Veterinarian(std::string name, double salary);
  std::string GetRole() const noexcept override;
  
  void Diagnose(animals::Animal& animal,
                animals::medical::MedicalRecordBook& record_book,
                animals::medical::Diagnosis diagnosis);
};

}  // namespace staff

#endif  // STAFF_VETERINARIAN_H_
