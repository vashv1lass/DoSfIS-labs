#ifndef PAYMENT_CONTEXT_H_
#define PAYMENT_CONTEXT_H_

#include <memory>

#include "payment/account.h"

namespace payment {

class PaymentContext {
public:
  explicit PaymentContext(std::shared_ptr<Account> oceanarium_account);

  Account& GetAquariumAccount() noexcept;
  const Account& GetAquariumAccount() const noexcept;

private:
  std::shared_ptr<Account> aquarium_account_;
};

}  // namespace payment

#endif  // PAYMENT_CONTEXT_H_