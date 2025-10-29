/**
 * @file utils/exceptions/already_exists_errors.h
 * @brief Declaration of the MemberAlreadyExistsError class.
 */

#ifndef ALREADY_EXISTS_ERRORS_H_
#define ALREADY_EXISTS_ERRORS_H_

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
 * @class MemberAlreadyExistsError
 * @brief Exception thrown when attempting to create a member that already exists.
 */
class MemberAlreadyExistsError : public AlreadyExistsError {
public:
  /**
   * @brief Constructor for MemberAlreadyExistsError class.
   * @param message The error message describing the exception.
   */
  explicit MemberAlreadyExistsError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // ALREADY_EXISTS_ERRORS_H_