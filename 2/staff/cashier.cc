#include "staff/cashier.h"

#include <iostream>
#include <string>

#include "payment/transaction.h"

namespace staff {

Cashier::Cashier(std::string name, double salary)
    : Employee(std::move(name), salary) {}

std::string Cashier::GetRole() const noexcept { return "Cashier"; }

void Cashier::ProcessTransaction(payment::Transaction& transaction) {
  transaction.Process();
  std::cout << "Cashier " << name_ << " processed the transaction.\n";
}

}  // namespace staff