#ifndef PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_ONLINE_CARD_PAYMENT_H_
#define PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_ONLINE_CARD_PAYMENT_H_

#include <memory>
#include <string>

#include "payment/context.h"
#include "payment/account.h"
#include "payment/payment_methods/card_payment/card_payment.h"

namespace payment {
namespace payment_methods {

class OnlineCardPayment : public CardPayment {
 public:
  OnlineCardPayment(PaymentContext& context,
                    std::shared_ptr<Account> card_account,
                    std::string cvv);
  void Pay(Account& customer, double amount) override;
  std::string GetPaymentMethodInfo() const noexcept override;
  
 private:
  std::string cvv_;
  
  bool VerifyCardData_() const noexcept;
};

}  // namespace payment_methods
}  // namespace payment

#endif  // PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_ONLINE_CARD_PAYMENT_H_