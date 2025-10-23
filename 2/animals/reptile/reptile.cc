#include "animals/reptile/reptile.h"

#include <iostream>

namespace animals {

Reptile::Reptile(std::string name, double body_temperature)
    : Animal(std::move(name)), body_temperature_(body_temperature) {
  if (body_temperature_ < 0.0 || body_temperature_ > 60.0) {
    throw std::out_of_range("Body temperature must be between "
                            "0 and 60 degrees Celsius.");
  }
}

void Reptile::Move() const noexcept {
  std::cout << name_ << " crawls slowly.\n";
}

void Reptile::Eat() const noexcept {
  std::cout << name_ << " eats insects.\n";
}

std::string Reptile::GetSpecies() const noexcept { return "Reptile"; }

void Reptile::SetBodyTemperature(double temperature) {
  if (temperature < 0.0 || temperature > 60.0) {
    throw std::out_of_range("Body temperature must be between "
                            "0 and 60 degrees Celsius.");
  }
  body_temperature_ = temperature;
}

double Reptile::GetBodyTemperature() const noexcept { return body_temperature_; }

}  // namespace animals