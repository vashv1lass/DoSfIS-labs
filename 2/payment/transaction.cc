#include "payment/transaction.h"

#include <iostream>

#include "payment/payment_methods/payment_method_interfaces.h"

namespace payment {

Transaction::Transaction(std::string visitor_name,
                         Ticket ticket,
                         std::unique_ptr<payment_methods::IPaymentMethod> method,
                         std::shared_ptr<Account> visitor_account)
    : visitor_name_(std::move(visitor_name)),
      ticket_(std::move(ticket)),
      method_(std::move(method)),
      visitor_account_(std::move(visitor_account)),
      is_paid_(false) {
  if (visitor_name_.empty()) {
    throw std::invalid_argument("Visitor name cannot be empty.");
  }
  if (!method_) {
    throw std::invalid_argument("Payment method cannot be null.");
  }
}

void Transaction::Process() {
  if (is_paid_) {
    throw std::runtime_error("Transaction already processed.");
  }

  double total = ticket_.GetPrice();

  if (auto* account_method = dynamic_cast<payment_methods::IAccountPaymentMethod*>(method_.get())) {
    if (!visitor_account_) {
      throw std::runtime_error("Account-based payment requires an account.");
    }

    account_method->Pay(*visitor_account_, total);
  } else {
    method_->Pay(total);
  }

  is_paid_ = true;

  std::cout << "Transaction complete for " << visitor_name_
            << " (" << method_->GetPaymentMethodInfo() << ").\n";
}

double Transaction::GetTotalAmount() const noexcept {
  return ticket_.GetPrice();
}

}  // namespace payment