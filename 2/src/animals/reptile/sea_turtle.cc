#include "animals/reptile/sea_turtle.h"

#include <iostream>

namespace animals {

SeaTurtle::SeaTurtle(std::string name, double body_temperature,
                     double shell_diameter)
    : Reptile(std::move(name), body_temperature),
      shell_diameter_(shell_diameter) {
  if (shell_diameter_ <= 0.0 || shell_diameter_ > 500.0) {
    throw std::out_of_range("Shell diameter must be positive "
                            "and less or equal to 500 cm.");
  }
}

void SeaTurtle::Move() const noexcept {
  std::cout << name_ << " swims calmly with shell diameter of "
            << shell_diameter_ << " cm.\n";
}

std::string SeaTurtle::GetSpecies() const noexcept { return "Sea Turtle"; }

double SeaTurtle::GetShellDiameter() const noexcept { return shell_diameter_; }

}  // namespace animals