/**
 * @file payment/payment_methods/payment_method_interfaces.h
 * @brief Declaration of the payment method interfaces.
 */

#ifndef PAYMENT_PAYMENT_METHODS_PAYMENT_METHOD_INTERFACES_H_
#define PAYMENT_PAYMENT_METHODS_PAYMENT_METHOD_INTERFACES_H_

#include <string>

// Forward declaration for Account and Transaction classes in payment namespace
namespace payment {

class Account;
class Transaction;

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
 * @class IPaymentMethod
 * @brief Abstract interface for payment methods that do not require an account.
 */
class IPaymentMethod {
public:
  /**
   * @brief Virtual destructor for IPaymentMethod class.
   */
  virtual ~IPaymentMethod() = default;

  /**
   * @brief Pure virtual function to get payment method information.
   * @return A string containing information about the payment method.
   */
  virtual std::string GetPaymentMethodInfo() const noexcept = 0;
protected:
  /**
   * @brief Pure virtual function to perform a payment.
   * @param amount The amount to pay.
   */
  virtual void Pay(double amount) = 0;

  friend class payment::Transaction;  // Granting access to Transaction class
};

/**
 * @class IAccountPaymentMethod
 * @brief Abstract interface for payment methods that require an account.
 */
class IAccountPaymentMethod {
public:
  /**
   * @brief Virtual destructor for IAccountPaymentMethod class.
   */
  virtual ~IAccountPaymentMethod() = default;

  /**
   * @brief Pure virtual function to get payment method information.
   * @return A string containing information about the payment method.
   */
  virtual std::string GetPaymentMethodInfo() const noexcept = 0;

protected:
  /**
   * @brief Pure virtual function to perform a payment using an account.
   * @param account Reference to the account to use for payment.
   * @param amount The amount to pay.
   * @note This function is protected to restrict access to payment processing.
   */
  virtual void Pay(payment::Account& account, double amount) = 0;

  friend class payment::Transaction;  // Granting access to Transaction class
};

}  // namespace payment_methods
}  // namespace payment

#endif  // PAYMENT_PAYMENT_METHODS_PAYMENT_METHOD_INTERFACES_H_