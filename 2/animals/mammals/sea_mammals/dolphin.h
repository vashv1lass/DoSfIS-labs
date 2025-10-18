#ifndef ANIMALS_MAMMALS_DOLPHIN_H_
#define ANIMALS_MAMMALS_DOLPHIN_H_

#include "sea_mammal.h"

#include <string>

class Dolphin : public SeaMammal {
public:
    Dolphin(const MedicalCard &, const Tank &, double, int);

    void SetMilkProduction(double) override;
    
    int GetIQ() const noexcept;

    void TrainToDraw() noexcept;
    bool CanDraw() const noexcept;

    std::string GetSpecies() const noexcept override;

    void Draw() const;
private:
    int iq_;
    bool can_draw_;
};


#endif // ANIMALS_MAMMALS_DOLPHIN_H_