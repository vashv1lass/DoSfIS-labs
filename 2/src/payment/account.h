/**
 * @file payment/account.h
 * @brief Declaration of the Account class.
 */

#ifndef PAYMENT_ACCOUNT_H_
#define PAYMENT_ACCOUNT_H_

#include <string>

/**
 * @brief Namespace for payment-related classes and functions.
 */
namespace payment {

/**
 * @class Account
 * @brief Represents a payment account with an owner and balance.
 */
class Account {
public:
  /**
   * @brief Constructor for Account class.
   * @param owner The name of the account owner.
   * @param balance The initial balance of the account.
   */
  explicit Account(std::string owner, double balance);

  /**
   * @brief Retrieves the name of the account owner.
   * @return The name of the account owner as a string.
   */
  const std::string& GetOwner() const noexcept;

  /**
   * @brief Retrieves the current balance of the account.
   * @return The current balance of the account.
   */
  double GetBalance() const noexcept;

  /**
   * @brief Deposits an amount into the account.
   * @param amount The amount to deposit.
   * @note The amount must be non-negative.
   */
  void Deposit(double amount);

  /**
   * @brief Withdraws an amount from the account.
   * @param amount The amount to withdraw.
   * @note The amount must be non-negative and not exceed the current balance.
   */
  void Withdraw(double amount);

  /**
   * @brief Checks if the account has enough balance for a transaction.
   * @param amount The amount to check against the balance.
   * @return True if the account has enough balance, false otherwise.
   */
  bool HasEnough(double amount) const noexcept;

private:
  std::string owner_;  /// The name of the account owner.
  double balance_;     /// The current balance of the account.
};

}  // namespace payment

#endif  // PAYMENT_ACCOUNT_H_