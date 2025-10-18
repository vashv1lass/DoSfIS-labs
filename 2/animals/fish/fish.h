#ifndef ANIMALS_FISH_FISH_H_
#define ANIMALS_FISH_FISH_H_

#include <string>

#include "animal.h"
#include "medical/medical_card.h"
#include "tank/tank.h"

class Fish : public virtual Animal {
public:
    Fish(const MedicalCard &, const Tank &);

    void SetTank(const Tank &) noexcept;
    Tank GetTank() const noexcept;
protected:
    Tank tank_;
};

#endif // ANIMALS_FISH_FISH_H_