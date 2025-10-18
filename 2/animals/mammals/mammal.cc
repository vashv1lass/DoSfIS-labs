#include "mammal.h"

#include <stdexcept>

#include "medical/medical_card.h"

Mammal::Mammal(const MedicalCard &medical_card, double milk_production)
    : milk_production_(milk_production) {}

double Mammal::GetMilkProduction() const noexcept {
    return milk_production_;
}