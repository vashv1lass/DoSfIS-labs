#ifndef ANIMALS_SHARK_H_
#define ANIMALS_SHARK_H_

#include "animal.h"

class Shark : public Animal {
public:
    Shark(const MedicalCard &, const Tank &, double);

    double GetPreferredDepth() const noexcept;
    std::string GetSpecies() const noexcept override;
private:
    double preferred_depth_;
};

#endif // ANIMALS_SHARK_H_