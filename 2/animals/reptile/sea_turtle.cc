#include "sea_turtle.h"

#include <string>
#include <stdexcept>

#include "medical/medical_card.h"
#include "tank/tank.h"
#include "animal.h"
#include "reptile.h"

SeaTurtle::SeaTurtle(const MedicalCard &medical_card, const Tank &tank,
    double body_temperature, const SeaTurtle::ShellType &shell_type
) : Animal(medical_card), Reptile(medical_card, tank, body_temperature), shell_type_(shell_type) {}

void SeaTurtle::SetBodyTemperature(double body_temperature) {
    if (body_temperature < 10 || body_temperature > 30) {
        throw std::out_of_range("Sea turtle body temperature must be between 10 and "
                                "30 degrees Celsius.");
    }
    body_temperature_ = body_temperature;
}

SeaTurtle::ShellType SeaTurtle::GetShellType() const noexcept {
    return this->shell_type_;
}

std::string SeaTurtle::GetSpecies() const noexcept {
    return "Sea turtle";
}