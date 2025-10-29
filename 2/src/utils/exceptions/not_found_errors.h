/**
 * @file utils/exceptions/not_found_errors.h
 * @brief Declaration of specific 'not found' exception classes.
 */

#ifndef NOT_FOUND_ERRORS_H_
#define NOT_FOUND_ERRORS_H_

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
 * @class EmployeeNotFoundError
 * @brief Exception thrown when an employee is not found.
 */
class EmployeeNotFoundError : public NotFoundError {
public:
  /**
   * @brief Constructor for EmployeeNotFoundError class.
   * @param message The error message describing the exception.
   */
  explicit EmployeeNotFoundError(std::string message);
};

/**
 * @class MedicalRecordBookNotFoundError
 * @brief Exception thrown when a medical record book is not found.
 */
class MedicalRecordBookNotFoundError : public NotFoundError {
public:
  /**
   * @brief Constructor for MedicalRecordBookNotFoundError class.
   * @param message The error message describing the exception.
   */
  explicit MedicalRecordBookNotFoundError(std::string message);
};

/**
 * @class TankNotFoundError
 * @brief Exception thrown when a tank is not found.
 */
class TankNotFoundError : public NotFoundError {
public:
  /**
   * @brief Constructor for TankNotFoundError class.
   * @param message The error message describing the exception.
   */
  explicit TankNotFoundError(std::string message);
};

/**
 * @class MemberNotFoundError
 * @brief Exception thrown when a member is not found.
 */
class MemberNotFoundError : public NotFoundError {
public:
  /**
   * @brief Constructor for MemberNotFoundError class.
   * @param message The error message describing the exception.
   */
  explicit MemberNotFoundError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // NOT_FOUND_ERRORS_H_