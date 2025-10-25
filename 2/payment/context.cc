#include "payment/context.h"

#include <stdexcept>

namespace payment {

PaymentContext::PaymentContext(std::shared_ptr<Account> aquarium_account)
    : aquarium_account_(std::move(aquarium_account)) {
  if (!aquarium_account_) {
    throw std::invalid_argument("Aquarium account cannot be null.");
  }
}

Account& PaymentContext::GetAquariumAccount() noexcept {
  return *aquarium_account_;
}

const Account& PaymentContext::GetAquariumAccount() const noexcept {
  return *aquarium_account_;
}

}  // namespace payment