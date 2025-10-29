#include "payment/transaction.h"

#include <iostream>
#include <stdexcept>

#include "payment/account.h"
#include "payment/payment_methods/payment_method_interfaces.h"
#include "utils/exceptions/payment_errors.h"

namespace payment {

Transaction::Transaction(std::string visitor_name,
                         Ticket ticket,
                         std::unique_ptr<payment_methods::IPaymentMethod> method)
    : visitor_name_(std::move(visitor_name)),
      ticket_(std::move(ticket)),
      method_(std::move(method)),
      account_method_(nullptr),
      is_paid_(false) {
  if (visitor_name_.empty()) {
    throw std::invalid_argument("Visitor name cannot be empty.");
  }
  if (!method_) {
    throw std::invalid_argument("Payment method cannot be null.");
  }
}

Transaction::Transaction(std::string visitor_name,
                         Ticket ticket,
                         std::unique_ptr<payment_methods::IAccountPaymentMethod> account_method,
                         std::shared_ptr<Account> visitor_account)
    : visitor_name_(std::move(visitor_name)),
      ticket_(std::move(ticket)),
      method_(nullptr),
      account_method_(std::move(account_method)),
      visitor_account_(std::move(visitor_account)),
      is_paid_(false) {
  if (visitor_name_.empty()) {
    throw std::invalid_argument("Visitor name cannot be empty.");
  }
  if (!account_method_) {
    throw std::invalid_argument("Account payment method cannot be null.");
  }
  if (!visitor_account_) {
    throw std::invalid_argument("Account-based payment requires an account.");
  }
}

void Transaction::Process() {
  if (is_paid_) {
    throw utils::exceptions::TransactionAlreadyProcessedError("Transaction already processed.");
  }

  double total = ticket_.GetPrice();

  if (method_) {
    method_->Pay(total);
    std::cout << "Transaction complete (cash/other) for " << visitor_name_ << ".\n";
  } else if (account_method_) {
    account_method_->Pay(*visitor_account_, total);
    std::cout << "Transaction complete (account) for " << visitor_name_ << ".\n";
  } else {
    throw utils::exceptions::MismatchingPaymentMethodError("Invalid payment configuration.");
  }

  is_paid_ = true;
}

double Transaction::GetTotalAmount() const noexcept {
  return ticket_.GetPrice();
}

}  // namespace payment