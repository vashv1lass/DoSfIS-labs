#include "reptile.h"

#include <stdexcept>

#include "medical/medical_card.h"
#include "tank/tank.h"

Reptile::Reptile(const MedicalCard &medical_card, const Tank &tank, double body_temperature)
    : tank_(tank), body_temperature_(body_temperature) {}

double Reptile::GetBodyTemperature() const noexcept {
    return body_temperature_;
}