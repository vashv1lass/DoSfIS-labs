#ifndef PAYMENT_PAYMENT_METHODS_CASH_PAYMENT_CASH_PAYMENT_H_
#define PAYMENT_PAYMENT_METHODS_CASH_PAYMENT_CASH_PAYMENT_H_

#include <string>

#include "payment/context.h"
#include "payment/payment_methods/payment_method_interfaces.h"
#include "payment/account.h"

namespace payment {
namespace payment_methods {

class CashPayment : public IPaymentMethod {
 public:
  explicit CashPayment(PaymentContext& context, double amount_given);
  void Pay(double amount) override;
  std::string GetPaymentMethodInfo() const noexcept override;

 private:
  PaymentContext& context_;
  double amount_given_;
};

}  // namespace payment_methods
}  // namespace payment

#endif  // PAYMENT_PAYMENT_METHODS_CASH_PAYMENT_CASH_PAYMENT_H_