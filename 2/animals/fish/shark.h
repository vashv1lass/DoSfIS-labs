#ifndef ANIMALS_SHARK_H_
#define ANIMALS_SHARK_H_

#include <string>

#include "fish.h"
#include "medical/medical_card.h"
#include "tank/tank.h"

class Shark : public Fish {
public:
    Shark(const MedicalCard &, const Tank &, double);

    double GetPreferredDepth() const noexcept;

    std::string GetSpecies() const noexcept override;
private:
    double preferred_depth_;
};

#endif // ANIMALS_SHARK_H_