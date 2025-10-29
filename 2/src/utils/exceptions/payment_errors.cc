#include "utils/exceptions/payment_errors.h"

namespace utils {
namespace exceptions {

InsufficientFundsError::InsufficientFundsError(std::string message)
    : PaymentError(std::move(message)) {}

CardVerificationError::CardVerificationError(std::string message)
    : PaymentError(std::move(message)) {}

TransactionAlreadyProcessedError::TransactionAlreadyProcessedError(std::string message)
    : PaymentError(std::move(message)) {}

MismatchingPaymentMethodError::MismatchingPaymentMethodError(std::string message)
    : PaymentError(std::move(message)) {}

}  // namespace exceptions
}  // namespace utils