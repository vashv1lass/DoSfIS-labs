#ifndef ANIMALS_REPTILE_REPTILE_H_
#define ANIMALS_REPTILE_REPTILE_H_

#include "animal.h"
#include "medical/medical_card.h"
#include "tank/tank.h"

class Reptile : public virtual Animal {
public:
    Reptile(const MedicalCard &, const Tank &, double);

    virtual void SetBodyTemperature(double) = 0;
    double GetBodyTemperature() const noexcept;
protected:
    Tank tank_;
    double body_temperature_;
};


#endif // ANIMALS_REPTILE_REPTILE_H_