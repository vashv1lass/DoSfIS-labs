#ifndef ANIMALS_REPTILE_SEA_TURTLE_H_
#define ANIMALS_REPTILE_SEA_TURTLE_H_

#include "reptile.h"

class SeaTurtle : public Reptile {
public:
    enum ShellType {
        CORIACEUS,
        GREEN
    };

    SeaTurtle(const MedicalCard &, const Tank &, double, const ShellType &);

    void SetBodyTemperature(double) override;

    ShellType GetShellType() const noexcept;

    std::string GetSpecies() const noexcept override;
private:
    ShellType shell_type_;
};

#endif // ANIMALS_SEA_TURTLE_H_