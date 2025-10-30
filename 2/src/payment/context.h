/**
 * @file payment/context.h
 * @brief Declaration of the PaymentContext class.
 */

#ifndef PAYMENT_CONTEXT_H_
#define PAYMENT_CONTEXT_H_

#include <memory>

#include "payment/account.h"

/**
 * @brief Namespace for payment-related classes and functions.
 */
namespace payment {

/**
 * @class PaymentContext
 * @brief Manages the payment context, including the aquarium's account.
 */
class PaymentContext {
public:
  /**
   * @brief Constructor for PaymentContext class.
   * @param oceanarium_account Shared pointer to the aquarium's account.
   */
  explicit PaymentContext(std::shared_ptr<Account> oceanarium_account);

  /**
   * @brief Retrieves the aquarium's account.
   * @return A reference to the aquarium's account.
   */
  Account& GetAquariumAccount() noexcept;

  /**
   * @brief Retrieves the aquarium's account.
   * @return A const reference to the aquarium's account.
   */
  const Account& GetAquariumAccount() const noexcept;

private:
  std::shared_ptr<Account> aquarium_account_;  /// Shared pointer to the aquarium's account.
};

}  // namespace payment

#endif  // PAYMENT_CONTEXT_H_