/**
 * @file payment/payment_methods/card_payment/online_card_payment.h
 * @brief Declaration of the OnlineCardPayment class.
 */

#ifndef PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_ONLINE_CARD_PAYMENT_H_
#define PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_ONLINE_CARD_PAYMENT_H_

#include <memory>
#include <string>

#include "payment/account.h"
#include "payment/context.h"
#include "payment/payment_methods/card_payment/card_payment.h"

/**
 * @brief Namespace for payment-related classes and functions.
 */
namespace payment {

/**
 * @brief Namespace for payment method implementations.
 */
namespace payment_methods {

/**
 * @class OnlineCardPayment
 * @brief Derived class representing an online card payment, inheriting from CardPayment.
 */
class OnlineCardPayment : public CardPayment {
public:
  /**
   * @brief Constructor for OnlineCardPayment class.
   * @param context Reference to the payment context.
   * @param card_account Shared pointer to the card account used for payment.
   * @param cvv The CVV code of the card.
   */
  OnlineCardPayment(PaymentContext& context,
                    std::shared_ptr<Account> card_account,
                    std::string cvv);

  /**
   * @brief Retrieves information about the online card payment method.
   * @return A string containing information about the payment method.
   * @note Overrides the GetPaymentMethodInfo function from the CardPayment base class.
   */
  std::string GetPaymentMethodInfo() const noexcept override;
  
private:
  std::string cvv_;  /// The CVV code of the card.
  
  /**
   * @brief Verifies the card data for online payment.
   * @return True if the card data is valid, false otherwise.
   * @note This function performs the necessary checks for online card validation.
   */
  bool VerifyCardData() const noexcept;

  /**
   * @brief Performs an online payment using the card account.
   * @param customer Reference to the customer's account to debit.
   * @param amount The amount to pay.
   * @note Overrides the Pay function from the CardPayment base class.
   */
  void Pay(Account& customer, double amount) override;
};

}  // namespace payment_methods
}  // namespace payment

#endif  // PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_ONLINE_CARD_PAYMENT_H_