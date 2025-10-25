#ifndef STAFF_VETERINARIAN_H_
#define STAFF_VETERINARIAN_H_

#include "staff/employee.h"
#include "animals/animal.h"
#include "animals/medical/diagnosis.h"
#include "animals/medical/medical.h"

#include <iostream>

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
