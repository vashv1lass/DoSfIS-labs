#ifndef ANIMALS_MAMMALS_SEAL_H_
#define ANIMALS_MAMMALS_SEAL_H_

#include <string>

#include "sea_mammal.h"

class Seal : public SeaMammal {
public:
    Seal(const MedicalCard &, const Tank &, double, double);

    void SetMilkProduction(double) override;

    void SetSwimSpeed(double);
    double GetSwimSpeed() const noexcept;

    void TrainToBalanceBall() noexcept;
    bool CanBalanceBall() const noexcept;

    std::string GetSpecies() const noexcept override;

    void BalanceBall() const;
private:
    double swim_speed_;
    bool can_balance_ball_;
};

#endif // ANIMALS_MAMMALS_SEAL_H_