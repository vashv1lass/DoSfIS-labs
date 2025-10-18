#include "stingray.h"

#include <string>
#include <stdexcept>

#include "medical/medical_card.h"
#include "tank/tank.h"
#include "animal.h"
#include "fish.h"

Stingray::Stingray(const MedicalCard &medical_card, const Tank &tank, double wingspan, bool is_venomous)
    : Animal(medical_card), Fish(medical_card, tank), wingspan_(wingspan), is_venomous_(is_venomous) {}

void Stingray::SetWingspan(double wingspan) {
    if (wingspan <= 0 || wingspan > 1200) {
        throw std::invalid_argument("Wingspan must be between 0 and 1200 cm.");
    }
    wingspan_ = wingspan;
}

double Stingray::GetWingspan() const noexcept {
    return wingspan_;
}

bool Stingray::IsVenomous() const noexcept {
    return is_venomous_;
}

std::string Stingray::GetSpecies() const noexcept {
    return "Stingray";
}