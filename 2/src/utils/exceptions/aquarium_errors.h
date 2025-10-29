/**
 * @file utils/exceptions/aquarium_errors.h
 * @brief Declaration of the ClosedAquariumError class.
 */

#ifndef AQUARIUM_ERRORS_H_
#define AQUARIUM_ERRORS_H_

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
 * @class ClosedAquariumError
 * @brief Exception thrown when attempting to perform an operation on a closed aquarium.
 */
class ClosedAquariumError : public BaseException {
public:
  /**
   * @brief Constructor for ClosedAquariumError class.
   * @param message The error message describing the exception.
   */
  explicit ClosedAquariumError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // AQUARIUM_ERRORS_H_