/**
 * @file utils/exceptions/base_exceptions.h
 * @brief Declaration of the base exception classes.
 */

#ifndef BASE_EXCEPTIONS_H_
#define BASE_EXCEPTIONS_H_

#include <stdexcept>

/**
 * @brief Namespace for utility functions and classes.
 */
namespace utils {

/**
 * @brief Namespace for exception classes.
 */
namespace exceptions {

/**
 * @class BaseException
 * @brief Base class for all custom exceptions in the system.
 */
class BaseException : public std::runtime_error {
public:
  /**
   * @brief Constructor for BaseException class.
   * @param message The error message describing the exception.
   */
  BaseException(std::string message);
};

/**
 * @class NotFoundError
 * @brief Exception thrown when a requested resource is not found.
 */
class NotFoundError : public BaseException {
public:
  /**
   * @brief Constructor for NotFoundError class.
   * @param message The error message describing the exception.
   */
  explicit NotFoundError(std::string message);
};

/**
 * @class AlreadyExistsError
 * @brief Exception thrown when attempting to create a resource that already exists.
 */
class AlreadyExistsError : public BaseException {
public:
  /**
   * @brief Constructor for AlreadyExistsError class.
   * @param message The error message describing the exception.
   */
  explicit AlreadyExistsError(std::string message);
};

/**
 * @class PaymentError
 * @brief Exception thrown when a payment operation fails.
 */
class PaymentError : public BaseException {
public:
  /**
   * @brief Constructor for PaymentError class.
   * @param message The error message describing the exception.
   */
  explicit PaymentError(std::string message);
};

/**
 * @class UnknownTypeError
 * @brief Exception thrown when an unknown type is encountered.
 */
class UnknownTypeError : public BaseException {
public:
  /**
   * @brief Constructor for UnknownTypeError class.
   * @param message The error message describing the exception.
   */
  explicit UnknownTypeError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // BASE_EXCEPTIONS_H_