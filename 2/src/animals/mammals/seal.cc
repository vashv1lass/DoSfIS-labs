#include "animals/mammals/seal.h"

#include <iostream>

namespace animals {

Seal::Seal(std::string name, double milk_production, double dive_depth,
           double breath_hold)
    : SeaMammal(std::move(name), milk_production, dive_depth, breath_hold),
      can_balance_ball_(false) {}

std::string Seal::GetSpecies() const noexcept { return "Seal"; }

bool Seal::CanBalanceBall() const noexcept {
  return can_balance_ball_;
}

void Seal::BalanceBall() const noexcept {
  if (can_balance_ball_) {
    std::cout << name_ << " balances a ball skillfully!\n";
  } else {
    std::cout << name_ << " hasn't learned to balance yet.\n";
  }
}

void Seal::LearnToBalanceBall() noexcept {
  can_balance_ball_ = true;
  std::cout << name_ << " learned to balance a ball!\n";
}

void Seal::Eat() const noexcept {
  std::cout << name_ << " eats fish and crustaceans.\n";
}

}  // namespace animals