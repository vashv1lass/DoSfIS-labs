#include "staff/veterinarian.h"

#include "animals/animal.h"

namespace staff {

Veterinarian::Veterinarian(std::string name, double salary)
    : Employee(std::move(name), salary) {}

std::string Veterinarian::GetRole() const noexcept { return "Veterinarian"; }

void Veterinarian::Diagnose(animals::Animal& animal,
                            animals::medical::MedicalRecordBook& record_book,
                            animals::medical::Diagnosis diagnosis) {
  std::cout << "Veterinarian " << name_ << " diagnoses "
            << animal.GetName() << ": "
            << diagnosis.GetDescription() << "\n";

  record_book.AddRecord(
    std::make_unique<animals::medical::MedicalRecord>(animals::medical::MedicalRecord(diagnosis))
  );
}

}  // namespace staff