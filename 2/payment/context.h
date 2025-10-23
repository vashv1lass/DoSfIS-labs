#ifndef PAYMENT_CONTEXT_H_
#define PAYMENT_CONTEXT_H_

#include <memory>

#include "payment/account.h"

namespace payment {

class PaymentContext {
 public:
  explicit PaymentContext(std::shared_ptr<Account> oceanarium_account);

  Account& GetOceanariumAccount() noexcept;
  const Account& GetOceanariumAccount() const noexcept;

 private:
  std::shared_ptr<Account> oceanarium_account_;
};

}  // namespace payment

#endif  // PAYMENT_CONTEXT_H_