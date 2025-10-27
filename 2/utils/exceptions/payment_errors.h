#ifndef PAYMENT_ERRORS_H_
#define PAYMENT_ERRORS_H_

#include "utils/exceptions/base_exceptions.h"

namespace utils {
namespace exceptions {

class InsufficientFundsError : public PaymentError {
public:
  explicit InsufficientFundsError(std::string message);
};

class CardVerificationError : public PaymentError {
public:
  explicit CardVerificationError(std::string message);
};

class TransactionAlreadyProcessedError : public PaymentError {
public:
  explicit TransactionAlreadyProcessedError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // PAYMENT_ERRORS_H_