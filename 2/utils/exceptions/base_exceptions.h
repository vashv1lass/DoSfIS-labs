#ifndef BASE_EXCEPTIONS_H_
#define BASE_EXCEPTIONS_H_

#include <stdexcept>

namespace utils {
namespace exceptions {

class BaseException : public std::runtime_error {
public:
  BaseException(std::string message);
};

class NotFoundError : public BaseException {
public:
  explicit NotFoundError(std::string message);
};

class AlreadyExistsError : public BaseException {
public:
  explicit AlreadyExistsError(std::string message);
};

class PaymentError : public BaseException {
public:
  explicit PaymentError(std::string message);
};

class UnknownTypeError : public BaseException {
public:
  explicit UnknownTypeError(std::string message);
};

}  // namespace exceptions
}  // namespace utils


#endif  // BASE_EXCEPTIONS_H_