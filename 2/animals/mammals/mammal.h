#ifndef ANIMALS_MAMMALS_MAMMAL_H_
#define ANIMALS_MAMMALS_MAMMAL_H_

#include "animal.h"
#include "medical/medical_card.h"

class Mammal : public virtual Animal {
public:
    Mammal(const MedicalCard &, double);

    virtual void SetMilkProduction(double) = 0;
    double GetMilkProduction() const noexcept;
protected:
    double milk_production_;
};

#endif // ANIMALS_MAMMALS_MAMMAL_H_