#include "trainer.h"

#include <string>

#include "utils/date.h"
#include "animals/mammals/sea_mammals/dolphin.h"
#include "animals/mammals/sea_mammals/seal.h"

Trainer::Trainer(
    const std::string &name, const Date &hire_date, double salary,
    const Specialization &specialization
) : Employee(name, hire_date, salary), specialization_(specialization) {}

Trainer::Specialization Trainer::GetSpecialization() const noexcept {
    return specialization_;
}

void Trainer::TrainAnimal(std::unique_ptr<Animal> animal) const {
    if (specialization_ == DOLPHINS && animal->GetSpecies() == "Dolphin") {
        dynamic_cast<Dolphin*>(animal.get())->TrainToDraw();
        return;
    } else if (specialization_ == SEALS && animal->GetSpecies() == "Seal") {
        dynamic_cast<Seal*>(animal.get())->TrainToBalanceBall();
        return;
    } else {
        // throw IncompatibleSpecializationException("Trainer specialization does not match animal type");
    }
}