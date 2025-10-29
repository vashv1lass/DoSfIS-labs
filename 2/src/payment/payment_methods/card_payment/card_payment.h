/**
 * @file payment/payment_methods/card_payment/card_payment.h
 * @brief Declaration of the CardPayment class.
 */

#ifndef PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_CARD_PAYMENT_H_
#define PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_CARD_PAYMENT_H_

#include <memory>
#include <string>

#include "payment/payment_methods/payment_method_interfaces.h"

// Forward declaration for PaymentContext and Account classes in payment namespace
namespace payment {

class PaymentContext;
class Account;

}  // namespace payment

/**
 * @brief Namespace for payment-related classes and functions.
 */
namespace payment {

/**
 * @brief Namespace for payment method implementations.
 */
namespace payment_methods {

/**
 * @class CardPayment
 * @brief Implementation of the IAccountPaymentMethod interface for card payments.
 */
class CardPayment : public IAccountPaymentMethod {
public:
  /**
   * @brief Constructor for CardPayment class.
   * @param context Reference to the payment context.
   * @param card_account Shared pointer to the card account used for payment.
   */
  CardPayment(PaymentContext& context, std::shared_ptr<Account> card_account);

  /**
   * @brief Retrieves information about the card payment method.
   * @return A string containing information about the payment method.
   * @note Overrides the GetPaymentMethodInfo function from the IAccountPaymentMethod interface.
   */
  std::string GetPaymentMethodInfo() const noexcept override;
  
protected:
  PaymentContext& context_;  /// Reference to the payment context.
  std::shared_ptr<Account> card_account_;  /// Shared pointer to the card account used for payment.

  /**
   * @brief Performs a payment using the card account.
   * @param customer Reference to the customer's account to debit.
   * @param amount The amount to pay.
   * @note Overrides the Pay function from the IAccountPaymentMethod interface.
   */
  void Pay(Account& customer, double amount) override;
};

}  // namespace payment
}  // namespace payment_methods

#endif  // PAYMENT_PAYMENT_METHODS_CARD_PAYMENT_CARD_PAYMENT_H_