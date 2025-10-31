#include "animals/mammals/seal.h"

#include <iostream>

#include "utils/exceptions/base_exceptions.h"

namespace animals {

Seal::Seal(std::string name, double milk_production, double dive_depth,
           double breath_hold)
    : SeaMammal(std::move(name), milk_production, dive_depth, breath_hold),
      can_balance_ball_(false) {}

std::string Seal::GetSpecies() const noexcept { return "Seal"; }

bool Seal::CanBalanceBall() const noexcept {
  return can_balance_ball_;
}

void Seal::BalanceBall() const {
  if (!can_balance_ball_) {
    throw utils::exceptions::CannotPerformActionException(
      name_ + " cannot balance a ball. It needs to learn first."
    );
  }
  std::cout << name_ << " balances a ball skillfully!\n";
}

void Seal::LearnToBalanceBall() noexcept {
  can_balance_ball_ = true;
}

void Seal::Eat() const noexcept {
  std::cout << name_ << " eats fish and crustaceans.\n";
}

}  // namespace animals