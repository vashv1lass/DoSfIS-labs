#ifndef ANIMALS_SEA_TURTLE_H_
#define ANIMALS_SEA_TURTLE_H_

#include "animal.h"

class SeaTurtle : public Animal {
public:
    enum ShellType {
        CORIACEUS,
        GREEN
    };

    SeaTurtle(const MedicalCard &, const Tank &, const ShellType &);

    ShellType GetShellType() const noexcept;

    std::string GetSpecies() const noexcept override;
private:
    ShellType shell_type_;
};

#endif // ANIMALS_SEA_TURTLE_H_