#include "animals/fish/shark.h"

#include <iostream>

namespace animals {

void Shark::Eat() const noexcept {
  std::cout << name_ << " hunts smaller fish.\n";
}

std::string Shark::GetSpecies() const noexcept {
  return "Shark";
}

}  // namespace animals