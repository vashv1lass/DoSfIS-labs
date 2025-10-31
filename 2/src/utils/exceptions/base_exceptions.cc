#include "utils/exceptions/base_exceptions.h"

namespace utils {
namespace exceptions {

BaseException::BaseException(std::string message)
    : std::runtime_error(std::move(message)) {}

NotFoundError::NotFoundError(std::string message)
    : BaseException(std::move(message)) {}

AlreadyExistsError::AlreadyExistsError(std::string message)
    : BaseException(std::move(message)) {}

PaymentError::PaymentError(std::string message)
    : BaseException(std::move(message)) {}

UnknownTypeError::UnknownTypeError(std::string message)
    : BaseException(std::move(message)) {}

CannotPerformActionException::CannotPerformActionException(std::string message)
    : BaseException(std::move(message)) {}

}  // namespace exceptions
}  // namespace utils