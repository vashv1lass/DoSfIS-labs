#ifndef PAYMENT_PAYMENT_METHODS_PAYMENT_METHOD_INTERFACES_H_
#define PAYMENT_PAYMENT_METHODS_PAYMENT_METHOD_INTERFACES_H_

#include <string>

#include "payment/account.h"

namespace payment {
namespace payment_methods {

class IPaymentMethod {
 public:
  virtual ~IPaymentMethod() = default;
  virtual void Pay(double amount) = 0;
  virtual std::string GetPaymentMethodInfo() const noexcept = 0;
};

class IAccountPaymentMethod : public IPaymentMethod {
 public:
  virtual void Pay(Account& customer, double amount) = 0;
};

}  // namespace payment_meth
}  // namespace payment

#endif  // PAYMENT_PAYMENT_METHODS_PAYMENT_METHOD_INTERFACES_H_