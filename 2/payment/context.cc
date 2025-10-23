#include "payment/context.h"

#include <stdexcept>

namespace payment {

PaymentContext::PaymentContext(std::shared_ptr<Account> oceanarium_account)
    : oceanarium_account_(std::move(oceanarium_account)) {
  if (!oceanarium_account_) {
    throw std::invalid_argument("Oceanarium account cannot be null.");
  }
}

Account& PaymentContext::GetOceanariumAccount() noexcept {
  return *oceanarium_account_;
}

const Account& PaymentContext::GetOceanariumAccount() const noexcept {
  return *oceanarium_account_;
}

}  // namespace payment