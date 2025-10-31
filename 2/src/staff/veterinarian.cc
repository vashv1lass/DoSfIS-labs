#include "staff/veterinarian.h"

#include "animals/animal.h"
#include "infrastructure/medical_department.h"

namespace staff {

Veterinarian::Veterinarian(std::string name, double salary)
    : Employee(std::move(name), salary) {}

std::string Veterinarian::GetRole() const noexcept { return "Veterinarian"; }

void Veterinarian::Diagnose(animals::Animal& animal,
                            infrastructure::MedicalDepartment& department,
                            animals::medical::Diagnosis diagnosis) {
  department.AddRecord(animal.GetName(), diagnosis, *this);
}

}  // namespace staff