#include "shark.h"

Shark::Shark(
    const MedicalCard &medical_card,
    const Tank &tank,
    double preferred_depth
) : Animal(medical_card, tank), preferred_depth_(preferred_depth) {}

double Shark::GetPreferredDepth() const noexcept {
    return this->preferred_depth_;
}

std::string Shark::GetSpecies() const noexcept {
    return "Shark";
}