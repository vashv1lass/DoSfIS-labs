#ifndef ANIMALS_STINGRAY_H_
#define ANIMALS_STINGRAY_H_

#include <string>

#include "fish.h"
#include "medical/medical_card.h"
#include "tank/tank.h"

class Stingray : public Fish {
public:
    Stingray(const MedicalCard &, const Tank &, double, bool);

    void SetWingspan(double);
    double GetWingspan() const noexcept;

    bool IsVenomous() const noexcept;

    std::string GetSpecies() const noexcept override;
private:
    double wingspan_;
    bool is_venomous_;
};

#endif // ANIMALS_STINGRAY_H_