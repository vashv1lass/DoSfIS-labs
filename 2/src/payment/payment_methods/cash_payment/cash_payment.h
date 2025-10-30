/**
 * @file payment/payment_methods/cash_payment/cash_payment.h
 * @brief Declaration of the CashPayment class.
 */

#ifndef PAYMENT_PAYMENT_METHODS_CASH_PAYMENT_CASH_PAYMENT_H_
#define PAYMENT_PAYMENT_METHODS_CASH_PAYMENT_CASH_PAYMENT_H_

#include <string>

#include "payment/account.h"
#include "payment/context.h"
#include "payment/payment_methods/payment_method_interfaces.h"

/**
 * @brief Namespace for payment-related classes and functions.
 */
namespace payment {

/**
 * @brief Namespace for payment method implementations.
 */
namespace payment_methods {

/**
 * @class CashPayment
 * @brief Implementation of the IPaymentMethod interface for cash payments.
 */
class CashPayment : public IPaymentMethod {
public:
  /**
   * @brief Constructor for CashPayment class.
   * @param context Reference to the payment context.
   * @param amount_given The amount of cash provided by the customer.
   */
  explicit CashPayment(PaymentContext& context, double amount_given);

  /**
   * @brief Retrieves information about the cash payment method.
   * @return A string containing information about the payment method.
   * @note Overrides the GetPaymentMethodInfo function from the IPaymentMethod interface.
   */
  std::string GetPaymentMethodInfo() const noexcept override;

private:
  PaymentContext& context_;  /// Reference to the payment context.
  double amount_given_;      /// The amount of cash provided by the customer.

  /**
   * @brief Performs a cash payment.
   * @param amount The amount to pay.
   * @note Overrides the Pay function from the IPaymentMethod interface.
   */
  void Pay(double amount) override;
};

}  // namespace payment_methods
}  // namespace payment

#endif  // PAYMENT_PAYMENT_METHODS_CASH_PAYMENT_CASH_PAYMENT_H_