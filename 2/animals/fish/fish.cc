#include "animals/fish/fish.h"

#include <iostream>

namespace animals {

Fish::Fish(std::string name, double swim_speed)
    : Animal(std::move(name)), swim_speed_(swim_speed) {
  if (swim_speed_ <= 0.0 || swim_speed_ > 50.0) {
    throw std::out_of_range("Swim speed must be positive "
                            "and less or equal to 50 m/s.");
  }
}

void Fish::Move() const noexcept {
  std::cout << name_ << " swims at " << swim_speed_ << " m/s.\n";
}

void Fish::Eat() const noexcept {
  std::cout << name_ << " eats plankton.\n";
}

std::string Fish::GetSpecies() const noexcept { return "Fish"; }

double Fish::GetSwimSpeed() const noexcept { return swim_speed_; }

void Fish::SetSwimSpeed(double speed) {
  if (speed <= 0.0 || speed > 50.0) {
    throw std::out_of_range("Swim speed must be positive "
                            "and less or equal to 50 m/s.");
  }
  swim_speed_ = speed;
}

}  // namespace animals