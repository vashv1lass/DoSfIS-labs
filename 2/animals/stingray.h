#ifndef ANIMALS_STINGRAY_H_
#define ANIMALS_STINGRAY_H_

#include "animal.h"

class Stingray : public Animal {
public:
    Stingray(const MedicalCard &, const Tank &, double, bool);

    void SetWingspan(double);

    bool IsVenomous() const noexcept;
    double GetWingspan() const noexcept;

    std::string GetSpecies() const noexcept override;
private:
    double wingspan_;
    bool is_venomous_;
};

#endif // ANIMALS_STINGRAY_H_