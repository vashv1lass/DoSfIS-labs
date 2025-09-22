#include "sea_turtle.h"

SeaTurtle::SeaTurtle(
    const MedicalCard &medical_card,
    const Tank &tank,
    const SeaTurtle::ShellType &shell_type
) : Animal(medical_card, tank), shell_type_(shell_type) {}

SeaTurtle::ShellType SeaTurtle::GetShellType() const noexcept {
    return this->shell_type_;
}

std::string SeaTurtle::GetSpecies() const noexcept {
    return "Sea turtle";
}