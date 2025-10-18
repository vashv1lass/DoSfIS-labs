#include "sea_mammal.h"

SeaMammal::SeaMammal(const MedicalCard &medical_card, const Tank &tank,
                     double milk_production)
    : Animal(medical_card), Fish(medical_card, tank), Mammal(medical_card, milk_production) {}