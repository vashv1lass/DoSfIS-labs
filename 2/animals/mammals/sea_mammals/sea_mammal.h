#ifndef ANIMALS_MAMMALS_SEA_MAMMALS_SEA_MAMMAL_H_
#define ANIMALS_MAMMALS_SEA_MAMMALS_SEA_MAMMAL_H

#include "mammals/mammal.h"
#include "fish/fish.h"

class SeaMammal : public Mammal, public Fish {
public:
    SeaMammal(const MedicalCard &, const Tank &, double);
};

#endif // ANIMALS_MAMMALS_SEA_MAMMALS_SEA_MAMMAL_H_