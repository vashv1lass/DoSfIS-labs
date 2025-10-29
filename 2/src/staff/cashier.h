/**
 * @file staff/cashier.h
 * @brief Declaration of the Cashier class.
 */

#ifndef STAFF_CASHIER_H_
#define STAFF_CASHIER_H_

#include <string>

#include "staff/employee.h"

// Forward declaration of Transaction class in payment namespaces
namespace payment {

class Transaction;

}  // namespace payment

/**
 * @brief Namespace for all staff-related classes and functions.
 */
namespace staff {

/**
 * @class Cashier
 * @brief Derived class representing a cashier, inheriting from Employee.
 */
class Cashier : public Employee {
public:
  /**
   * @brief Constructor for Cashier class.
   * @param name The name of the cashier.
   * @param salary The salary of the cashier.
   */
  Cashier(std::string name, double salary);

  /**
   * @brief Retrieves the role of the cashier.
   * @return The role as a string ("Cashier").
   * @note Overrides the GetRole function from the Employee base class.
   */
  std::string GetRole() const noexcept override;

  /**
   * @brief Creates a payment transaction.
   * @param visitor_name The name of the visitor making the purchase.
   * @param ticket The ticket being purchased.
   * @param method Unique pointer to the payment method to use.
   * @return Unique pointer to the created Transaction object.
   */
  std::unique_ptr<payment::Transaction> CreateTransaction(
      std::string visitor_name,
      payment::Ticket ticket,
      std::unique_ptr<payment::payment_methods::IPaymentMethod> method);
  
  /**
   * @brief Creates a payment transaction using an account-based payment method.
   * @param visitor_name The name of the visitor making the purchase.
   * @param ticket The ticket being purchased.
   * @param method Unique pointer to the account-based payment method to use.
   * @param account Shared pointer to the visitor's account.
   * @return Unique pointer to the created Transaction object.
   */
  std::unique_ptr<payment::Transaction> CreateTransaction(
      std::string visitor_name,
      payment::Ticket ticket,
      std::unique_ptr<payment::payment_methods::IAccountPaymentMethod> method,
      std::shared_ptr<payment::Account> account);

  /**
   * @brief Processes a payment transaction.
   * @param transaction Reference to the transaction to process.
   * @note This function handles the payment and completes the transaction.
   */
  void ProcessTransaction(payment::Transaction& transaction);
};

}  // namespace staff

#endif  // STAFF_CASHIER_H_