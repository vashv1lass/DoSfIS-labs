#ifndef PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_CARD_PAYMENT_H_
#define PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_CARD_PAYMENT_H_

#include <string>
#include <memory>

#include "payment/payment_methods/payment_method_interfaces.h"

namespace payment {

class PaymentContext;
class Account;

}  // namespace payment

namespace payment {
namespace payment_methods {

class CardPayment : public IAccountPaymentMethod {
public:
  CardPayment(PaymentContext& context, std::shared_ptr<Account> card_account);
  void Pay(Account& customer, double amount) override;
  std::string GetPaymentMethodInfo() const noexcept override;
  
protected:
  PaymentContext& context_;
  std::shared_ptr<Account> card_account_;
};

}  // namespace payment
}  // namespace payment_methods

#endif  // PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_CARD_PAYMENT_H_