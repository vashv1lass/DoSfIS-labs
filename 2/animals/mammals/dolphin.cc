#include "animals/mammals/dolphin.h"

#include <iostream>

namespace animals {

Dolphin::Dolphin(std::string name, double milk_production, double dive_depth,
                 double breath_hold, int iq)
    : SeaMammal(std::move(name), milk_production, dive_depth, breath_hold),
      iq_(iq),
      can_draw_(false) {
  if (iq_ <= 0.0 || iq_ > 200) {
    throw std::out_of_range("IQ must be positive and less or equal to 200.");
  }
}

void Dolphin::Eat() const noexcept {
  std::cout << name_ << " eats small fish.\n";
}

std::string Dolphin::GetSpecies() const noexcept { return "Dolphin"; }

bool Dolphin::CanDraw() const noexcept { return can_draw_; }

void Dolphin::LearnToDraw() noexcept {
  if (iq_ > 120) {
    can_draw_ = true;
    std::cout << name_ << " learned to draw!\n";
  } else {
    std::cout << name_ << " is not intelligent enough to learn drawing.\n";
  }
}

void Dolphin::Draw() const noexcept {
  if (can_draw_) {
    std::cout << name_ << " draws a beautiful picture.\n";
  } else {
    std::cout << name_ << " doesn't know how to draw.\n";
  }
}

}  // namespace animals