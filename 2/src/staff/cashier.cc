#include "staff/cashier.h"

#include <iostream>
#include <string>

#include "payment/transaction.h"

namespace staff {

Cashier::Cashier(std::string name, double salary)
    : Employee(std::move(name), salary) {}

std::string Cashier::GetRole() const noexcept { return "Cashier"; }

std::unique_ptr<payment::Transaction> Cashier::CreateTransaction(
    std::string visitor_name,
    payment::Ticket ticket,
    std::unique_ptr<payment::payment_methods::IPaymentMethod> method) {
  return std::unique_ptr<payment::Transaction>(
      new payment::Transaction(std::move(visitor_name), std::move(ticket), std::move(method)));
}

std::unique_ptr<payment::Transaction> Cashier::CreateTransaction(
    std::string visitor_name,
    payment::Ticket ticket,
    std::unique_ptr<payment::payment_methods::IAccountPaymentMethod> method,
    std::shared_ptr<payment::Account> account) {
  return std::unique_ptr<payment::Transaction>(
      new payment::Transaction(std::move(visitor_name), std::move(ticket), std::move(method), std::move(account)));
}

void Cashier::ProcessTransaction(payment::Transaction& transaction) {
  transaction.Process();
}

}  // namespace staff