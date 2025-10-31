#include "animals/fish/shark.h"

#include <iostream>

namespace animals {

Shark::Shark(std::string name, double swim_speed)
    : Fish(std::move(name), swim_speed) {}

void Shark::Eat() const noexcept {
  std::cout << name_ << " eats smaller fish.\n";
}

std::string Shark::GetSpecies() const noexcept {
  return "Shark";
}

}  // namespace animals