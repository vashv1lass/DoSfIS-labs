/**
 * @file payment/transaction.h
 * @brief Declaration of the Transaction class.
 */

#ifndef PAYMENT_TRANSACTION_H_
#define PAYMENT_TRANSACTION_H_

#include <memory>
#include <string>

#include "payment/account.h"
#include "payment/payment_methods/payment_method_interfaces.h"
#include "payment/ticket.h"

namespace payment::payment_methods {

class IPaymentMethod;
class IAccountPaymentMethod;

}

namespace staff {

class Cashier;

}

/**
 * @brief Namespace for payment-related classes and functions.
 */
namespace payment {

/**
 * @class Transaction
 * @brief Represents a payment transaction for a ticket purchase.
 */
class Transaction {
public:
  /**
   * @brief Retrieves the total amount of the transaction.
   * @return The total amount of the transaction.
   */
  double GetTotalAmount() const noexcept;
private:
  std::string visitor_name_;  /// The name of the visitor making the purchase.
  Ticket ticket_;             /// The ticket being purchased.
  std::unique_ptr<payment_methods::IPaymentMethod> method_;  /// The payment method to use (for non-account transactions).
  std::unique_ptr<payment_methods::IAccountPaymentMethod> account_method_;  /// The account-based payment method to use (for account transactions).
  std::shared_ptr<Account> visitor_account_;  /// The visitor's account (for account-based transactions).
  bool is_paid_;  /// Indicates whether the transaction has been successfully processed.

  /**
   * @brief Constructor for Transaction class using a payment method without an account.
   * @param visitor_name The name of the visitor making the purchase.
   * @param ticket The ticket being purchased.
   * @param method Unique pointer to the payment method to use.
   */
  Transaction(std::string visitor_name,
              Ticket ticket,
              std::unique_ptr<payment_methods::IPaymentMethod> method);

  /**
   * @brief Constructor for Transaction class using a payment method with an account.
   * @param visitor_name The name of the visitor making the purchase.
   * @param ticket The ticket being purchased.
   * @param account_method Unique pointer to the account-based payment method to use.
   * @param visitor_account Shared pointer to the visitor's account.
   */
  Transaction(std::string visitor_name,
              Ticket ticket,
              std::unique_ptr<payment_methods::IAccountPaymentMethod> account_method,
              std::shared_ptr<Account> visitor_account);

  /**
   * @brief Processes the transaction.
   * @note This function executes the payment and completes the ticket purchase.
   * @note Accessible only for staff::Cashier
   */
  void Process();

  friend class staff::Cashier;
};

}  // namespace payment

#endif  // PAYMENT_TRANSACTION_H_