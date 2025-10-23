#include "payment/payment_methods/card_payment/card_payment.h"

#include <iostream>
#include <stdexcept>

namespace payment {
namespace payment_methods {

CardPayment::CardPayment(PaymentContext& context, std::shared_ptr<Account> card_account)
    : context_(context), card_account_(std::move(card_account)) {
  if (!card_account_) {
    throw std::invalid_argument("Card account cannot be null.");
  }
}

void CardPayment::Pay(Account& customer, double amount) {
  if (amount <= 0.0) {
    throw std::invalid_argument("Amount must be positive.");
  }
  if (!card_account_->HasEnough(amount)) {
    throw std::runtime_error("Insufficient funds on card.");
  }

  card_account_->Withdraw(amount);
  context_.GetOceanariumAccount().Deposit(amount);

  std::cout << "Card charged: " << amount <<
               " BYN from " << card_account_->GetOwner() << ".\n";
}

std::string CardPayment::GetPaymentMethodInfo() const noexcept {
  return "Card Payment (POS)";
}

}  // namespace payment_methods
}  // namespace payment