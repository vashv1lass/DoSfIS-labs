#include "animals/mammals/dolphin.h"

#include <iostream>

#include "utils/exceptions/base_exceptions.h"

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

std::string Dolphin::GetSpecies() const noexcept { return "Dolphin"; }

int Dolphin::GetIQ() const noexcept { return iq_; }

bool Dolphin::CanDraw() const noexcept { return can_draw_; }

void Dolphin::Draw() const {
  if (!can_draw_) {
    throw utils::exceptions::CannotPerformActionException(
      name_ + " cannot draw. It needs to learn first."
    );
  }
  std::cout << name_ << " draws a beautiful picture.\n";
}

void Dolphin::Eat() const noexcept {
  std::cout << name_ << " eats small fish.\n";
}

void Dolphin::LearnToDraw() {
  if (iq_ <= 120) {
    throw utils::exceptions::CannotPerformActionException(
      name_ + " has insufficient IQ to learn drawing."
    );
  }

  can_draw_ = true;
}

}  // namespace animals