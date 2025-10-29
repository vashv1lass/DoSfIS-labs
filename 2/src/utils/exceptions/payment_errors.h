/**
 * @file utils/exceptions/payment_errors.h
 * @brief Declaration of specific payment-related exception classes.
 */

#ifndef PAYMENT_ERRORS_H_
#define PAYMENT_ERRORS_H_

#include "utils/exceptions/base_exceptions.h"

/**
 * @brief Namespace for utility functions and classes.
 */
namespace utils {

/**
 * @brief Namespace for exception classes.
 */
namespace exceptions {

/**
 * @class InsufficientFundsError
 * @brief Exception thrown when an account has insufficient funds for a transaction.
 */
class InsufficientFundsError : public PaymentError {
public:
  /**
   * @brief Constructor for InsufficientFundsError class.
   * @param message The error message describing the exception.
   */
  explicit InsufficientFundsError(std::string message);
};

/**
 * @class CardVerificationError
 * @brief Exception thrown when card verification fails during a payment.
 */
class CardVerificationError : public PaymentError {
public:
  /**
   * @brief Constructor for CardVerificationError class.
   * @param message The error message describing the exception.
   */
  explicit CardVerificationError(std::string message);
};

/**
 * @class TransactionAlreadyProcessedError
 * @brief Exception thrown when attempting to process a transaction that has already been processed.
 */
class TransactionAlreadyProcessedError : public PaymentError {
public:
  /**
   * @brief Constructor for TransactionAlreadyProcessedError class.
   * @param message The error message describing the exception.
   */
  explicit TransactionAlreadyProcessedError(std::string message);
};

/**
 * @class MismatchingPaymentMethodError
 * @brief Exception thrown when an incorrect payment method is used for a transaction type.
 */
class MismatchingPaymentMethodError : public PaymentError {
public:
  /**
   * @brief Constructor for MismatchingPaymentMethodError class.
   * @param message The error message describing the exception.
   */
  explicit MismatchingPaymentMethodError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // PAYMENT_ERRORS_H_