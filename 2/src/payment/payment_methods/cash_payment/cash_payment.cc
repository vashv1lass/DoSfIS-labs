#include "payment/payment_methods/cash_payment/cash_payment.h"

#include <iostream>
#include <stdexcept>

#include "payment/account.h"
#include "payment/context.h"
#include "utils/exceptions/payment_errors.h"

namespace payment {
namespace payment_methods {

CashPayment::CashPayment(PaymentContext& context, double amount_given)
    : context_(context), amount_given_(amount_given) {
  if (amount_given_ <= 0.0) {
    throw std::out_of_range("Amount of cash given must be positive.");
  }
}

void CashPayment::Pay(double amount) {
  if (amount <= 0.0) {
    throw std::out_of_range("Amount must be positive.");
  }
  if (amount_given_ < amount) {
    throw utils::exceptions::InsufficientFundsError("Insufficient cash provided.");
  }

  double change = amount_given_ - amount;
  context_.GetAquariumAccount().Deposit(amount);

  std::cout << "Given: " << amount_given_ << " BYN. Received: "
            << amount << " BYN. Change: " << change << " BYN.";
}

std::string CashPayment::GetPaymentMethodInfo() const noexcept {
  return "Cash Payment";
}

}  // namespace payment_methods
}  // namespace payment_methods