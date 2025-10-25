#include "payment/account.h"

#include <string>
#include <stdexcept>

namespace payment {

Account::Account(std::string owner, double balance)
    : owner_(std::move(owner)), balance_(balance) {
  if (owner_.empty()) {
    throw std::invalid_argument("Account owner name cannot be empty.");
  }
  if (balance_ < 0.0) {
    throw std::out_of_range("Initial balance cannot be negative.");
  }
}

const std::string& Account::GetOwner() const noexcept { return owner_; }

double Account::GetBalance() const noexcept { return balance_; }

void Account::Deposit(double amount) {
  if (amount <= 0.0) {
    throw std::invalid_argument("Deposit amount must be positive.");
  }
  balance_ += amount;
}

void Account::Withdraw(double amount) {
  if (amount <= 0.0) {
    throw std::invalid_argument("Withdraw amount must be positive.");
  }
  if (amount > balance_) {
    throw utils::exceptions::InsufficientFundsError("Balance is too low for withdrawal.");
  }
  balance_ -= amount;
}

bool Account::HasEnough(double amount) const noexcept {
  return amount <= balance_;
}

}  // namespace payment