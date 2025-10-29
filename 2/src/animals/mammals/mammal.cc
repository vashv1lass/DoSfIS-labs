#include "animals/mammals/mammal.h"

#include <iostream>

namespace animals {

Mammal::Mammal(std::string name, double milk_production)
    : Animal(std::move(name)), milk_production_(milk_production) {
  if (milk_production_ <= 0.0 || milk_production_ > 100.0) {
    throw std::out_of_range("Milk production must be positive "
                            "and less or equal to 100 liters per day.");
  }
}

void Mammal::Move() const noexcept {
  std::cout << name_ << " walks or runs.\n";
}

std::string Mammal::GetSpecies() const noexcept { return "Mammal"; }

void Mammal::SetMilkProduction(double milk_production) { 
  if (milk_production <= 0.0 || milk_production > 100.0) {
    throw std::out_of_range("Milk production must be positive "
                            "and less or equal to 100 liters per day.");
  }
  milk_production_ = milk_production;
}

double Mammal::GetMilkProduction() const noexcept { return milk_production_; }

void Mammal::Eat() const noexcept {
  std::cout << name_ << " eats plants or meat.\n";
}

SeaMammal::SeaMammal(std::string name, double milk_production,
                     double dive_depth, double breath_hold)
    : Mammal(std::move(name), milk_production),
      dive_depth_(dive_depth),
      breath_hold_time_(breath_hold) {
  if (dive_depth_ <= 0.0 || dive_depth_ > 5000.0) {
    throw std::out_of_range("Dive depth must be positive and "
                            "less or equal to 5000 meters.");
  }
  if (breath_hold_time_ <= 0.0 || breath_hold_time_ > 18000.0) {
    throw std::out_of_range("Breath hold time must be positive "
                            "and less or equal to 5 hours (18000 seconds).");
  }
}

void SeaMammal::Move() const noexcept {
  std::cout << name_ << " swims and can dive up to " << dive_depth_
            << " meters.\n";
}

std::string SeaMammal::GetSpecies() const noexcept { return "Sea Mammal"; }

double SeaMammal::GetDiveDepth() const noexcept { return dive_depth_; }

double SeaMammal::GetBreathHoldTime() const noexcept { return breath_hold_time_; }

}  // namespace animals