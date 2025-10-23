#include "animals/tank.h"

#include <iostream>

namespace animals {

Tank::Tank(double depth, double volume) : depth_(depth), volume_(volume) {
  if (depth_ <= 0.0 || depth_ > 100.0) {
    throw std::out_of_range("Tank depth must be positive and "
                            "less or equal to 100 meters.");
  }
  if (volume_ <= 0.0 || volume_ > 100000.0) {
    throw std::out_of_range("Tank volume must be positive and "
                            "less or equal to 100000 m³.");
  }
}

void Tank::AddAnimal(std::shared_ptr<Animal> animal) {
  if (!animal) {
    throw std::invalid_argument("Cannot add null animal to tank.");
  }
  animals_.push_back(std::move(animal));
}

void Tank::ShowAll() const noexcept {
  std::cout << "Tank depth: " << depth_ << " m, volume: " << volume_ << " m³\n";
  for (const auto& a : animals_) {
    std::cout << " - " << a->GetName() << " (" << a->GetSpecies() << ")\n";
  }
}

double Tank::GetDepth() const noexcept { return depth_; }

double Tank::GetVolume() const noexcept { return volume_; }

void Tank::SetDepth(double depth) {
  if (depth <= 0.0 || depth > 100.0) {
    throw std::out_of_range("Tank depth must be positive and "
                            "less or equal to 100 meters.");
  }
  depth_ = depth;
}

void Tank::SetVolume(double volume) {
  if (volume <= 0.0 || volume > 100000.0) {
    throw std::out_of_range("Tank volume must be positive and "
                            "less or equal to 100000 m³.");
  }
  volume_ = volume;
}

}  // namespace animals