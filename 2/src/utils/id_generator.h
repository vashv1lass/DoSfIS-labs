/**
 * @file utils/id_generator.h
 * @brief Declaration of the IDGenerator singleton class.
 */

#ifndef UTILS_ID_GENERATOR_H_
#define UTILS_ID_GENERATOR_H_

#include <atomic>

/**
 * @brief Namespace for utility functions and classes.
 */
namespace utils {

/**
 * @class IDGenerator
 * @brief Singleton class for generating unique IDs.
 */
class IDGenerator {
public:
  /**
   * @brief Gets the singleton instance of the IDGenerator.
   * @return A reference to the IDGenerator instance.
   */
  static IDGenerator& Instance() noexcept;

  /**
   * @brief Generates the next unique ID.
   * @return The next unique ID.
   * @note This function is thread-safe.
   */
  int NextID() noexcept;

private:
  /**
   * @brief Private constructor for the singleton pattern.
   */
  IDGenerator() = default;

  /**
   * @brief Destructor for the IDGenerator class.
   */
  ~IDGenerator() = default;

  /**
   * @brief Copy constructor is deleted.
   */
  IDGenerator(const IDGenerator&) = delete;

  /**
   * @brief Assignment operator is deleted.
   */
  IDGenerator& operator=(const IDGenerator&) = delete;

  std::atomic<int> counter_{0};  /// Atomic counter for generating unique IDs.
};

}  // namespace utils

#endif  // UTILS_ID_GENERATOR_H_