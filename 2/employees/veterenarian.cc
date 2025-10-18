#include "veterenarian.h"

#include <string>

#include "utils/date.h"

Veterenarian::Veterenarian(
    const std::string &name, const Date &hire_date, double salary,
    const Specialization &specialization, const std::string &license_number
) : Employee(name, hire_date, salary), specialization_(specialization), license_number_(license_number) {}

Veterenarian::Specialization Veterenarian::GetSpecialization() const noexcept {
    return specialization_;
}

std::string Veterenarian::GetLicenseNumber() const noexcept {
    return license_number_;
}

void Veterenarian::TreatAnimal(std::unique_ptr<Animal> animal) const {
    if (animal->GetMedicalCard().GetHealthStatus() == MedicalCard::HEALTHY) {
        return;
    }

    if (specialization_ == FISH && animal->GetSpecies() == "Stingray" || animal->GetSpecies() == "Shark") {
        animal->GetMedicalCard().SetHealthStatus(MedicalCard::HEALTHY);
    } else if (specialization_ == MAMMALS && (animal->GetSpecies() == "Dolphin" || animal->GetSpecies() == "Seal")) {
        animal->GetMedicalCard().SetHealthStatus(MedicalCard::HEALTHY);
    } else if (specialization_ == REPTILES && animal->GetSpecies() == "Sea turtle") {
        animal->GetMedicalCard().SetHealthStatus(MedicalCard::HEALTHY);
    } else {
        // throw IncompatibleSpecializationException("Veterenarian specialization does not match animal type");
    }
}