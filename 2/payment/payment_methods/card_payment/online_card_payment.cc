#include "payment/payment_methods/card_payment/online_card_payment.h"

#include <iostream>
#include <stdexcept>
#include <string>

namespace payment {
namespace payment_methods {

OnlineCardPayment::OnlineCardPayment(PaymentContext& context,
                                     std::shared_ptr<Account> card_account,
                                     std::string cvv)
    : CardPayment(context, std::move(card_account)), cvv_(std::move(cvv)) {
  if (!(cvv_.size() == 3 && isdigit(cvv_[0]) && isdigit(cvv_[1]) && isdigit(cvv_[2]))) {
    throw std::invalid_argument("Invalid CVV code.");
  }
}

bool OnlineCardPayment::VerifyCardData_() const noexcept {
  return true;  // maybe later idk
}

void OnlineCardPayment::Pay(Account &customer, double amount) {
  if (!VerifyCardData_()) {
    throw utils::exceptions::CardVerificationError("Card verification failed.");
  }
  if (amount <= 0.0) {
    throw std::out_of_range("Amount must be positive.");
  }

  card_account_->Withdraw(amount);
  context_.GetAquariumAccount().Deposit(amount);

  std::cout << "Online payment of " << amount << " BYN from "
            << card_account_->GetOwner() << " processed.\n";
}

std::string OnlineCardPayment::GetPaymentMethodInfo() const noexcept {
  return "Online Card Payment";
}

}  // namespace payment_methods
}  // namespace payment