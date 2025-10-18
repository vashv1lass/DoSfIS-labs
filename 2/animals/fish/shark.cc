#include "shark.h"

#include <string>

#include "medical/medical_card.h"
#include "tank/tank.h"
#include "animal.h"
#include "fish.h"

Shark::Shark(
    const MedicalCard &medical_card,
    const Tank &tank,
    double preferred_depth
) : Animal(medical_card), Fish(medical_card, tank), preferred_depth_(preferred_depth) {}

double Shark::GetPreferredDepth() const noexcept {
    return this->preferred_depth_;
}

std::string Shark::GetSpecies() const noexcept {
    return "Shark";
}