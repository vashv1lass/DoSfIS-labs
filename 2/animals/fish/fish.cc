#include "fish.h"

#include "medical/medical_card.h"
#include "tank/tank.h"

Fish::Fish(const MedicalCard &medical_card, const Tank &tank)
    : tank_(tank) {}

void Fish::SetTank(const Tank &tank) noexcept {
    tank_ = tank;
}

Tank Fish::GetTank() const noexcept {
    return tank_;
}