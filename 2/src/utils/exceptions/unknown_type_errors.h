/**
 * @file utils/exceptions/unknown_type_errors.h
 * @brief Declaration of specific 'unknown type' exception classes.
 */

#ifndef UNKNOWN_TYPE_ERRORS_H_
#define UNKNOWN_TYPE_ERRORS_H_

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
 * @class UnknownDiagnosisTypeError
 * @brief Exception thrown when an unknown diagnosis type is encountered.
 */
class UnknownDiagnosisTypeError : public UnknownTypeError {
public:
  /**
   * @brief Constructor for UnknownDiagnosisTypeError class.
   * @param message The error message describing the exception.
   */
  explicit UnknownDiagnosisTypeError(std::string message);
};

/**
 * @class UnknownTicketTypeError
 * @brief Exception thrown when an unknown ticket type is encountered.
 */
class UnknownTicketTypeError : public UnknownTypeError {
public:
  /**
   * @brief Constructor for UnknownTicketTypeError class.
   * @param message The error message describing the exception.
   */
  explicit UnknownTicketTypeError(std::string message);
};

/**
 * @class UnknownMembershipTypeError
 * @brief Exception thrown when an unknown membership type is encountered.
 */
class UnknownMembershipTypeError : public UnknownTypeError {
public:
  /**
   * @brief Constructor for UnknownMembershipTypeError class.
   * @param message The error message describing the exception.
   */
  explicit UnknownMembershipTypeError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // UNKNOWN_TYPE_ERRORS_H_