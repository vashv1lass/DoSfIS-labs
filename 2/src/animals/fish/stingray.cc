#include "animals/fish/stingray.h"

#include <iostream>

namespace animals {

Stingray::Stingray(std::string name, double swim_speed, bool venomous,
                   double fin_span)
    : Fish(std::move(name), swim_speed),
      venomous_(venomous),
      fin_span_(fin_span) {
  if (fin_span_ <= 0.0 || fin_span_ > 10.0) {
    throw std::out_of_range("Fin span must be positive "
                            "and less or equal to 10 meters.");
  }
}

void Stingray::Move() const noexcept {
  std::cout << name_ << " glides with fin span of " << fin_span_ << " meters.\n";
}

std::string Stingray::GetSpecies() const noexcept { return "Stingray"; }

bool Stingray::IsVenomous() const noexcept { return venomous_; }

void Stingray::SetFinSpan(double fin_span) {
    if (fin_span <= 0.0 || fin_span > 10.0) {
        throw std::out_of_range("Fin span must be positive "
                                "and less than or equal to 10 meters.");
    }
}

double Stingray::GetFinSpan() const { return fin_span_; }

}  // namespace animals