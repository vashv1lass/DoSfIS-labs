#include "stingray.h"

Stingray::Stingray(
    const MedicalCard &medical_card,
    const Tank &tank,
    double wingspan,
    bool is_venomous
) : Animal(medical_card, tank),
    wingspan_(wingspan), is_venomous_(is_venomous) {}

void Stingray::SetWingspan(double wingspan) {
    wingspan_ = wingspan;
}

bool Stingray::IsVenomous() const noexcept {
    return is_venomous_;
}

double Stingray::GetWingspan() const noexcept {
    return wingspan_;
}

std::string Stingray::GetSpecies() const noexcept {
    return "Stingray";
}