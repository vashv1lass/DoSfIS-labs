/**
 * @file infrastructure/ecosystem.h
 * @brief Declaration of the Ecosystem class.
 */

#ifndef INFRASTRUCTURE_ECOSYSTEM_H_
#define INFRASTRUCTURE_ECOSYSTEM_H_

#include <memory>
#include <string>
#include <vector>

// Forward declaration of Animal class in animals namespace
namespace animals {

class Animal;

}  // namespace animals

namespace infrastructure {

/**
 * @brief Namespace for all infrastructure-related classes and functions.
 */

/**
 * @class Ecosystem
 * @brief Manages the collection of animals within the aquarium ecosystem.
 */
class Ecosystem {
public:
  /**
   * @brief Default constructor for Ecosystem class.
   */
  Ecosystem() = default;

  /**
   * @brief Adds an animal to the ecosystem.
   * @param animal Unique pointer to the animal to add.
   */
  void AddAnimal(std::unique_ptr<animals::Animal> animal);

  /**
   * @brief Generates a status report for all animals in the ecosystem.
   * @return A vector of strings containing the status report.
   */
  std::vector<std::string> GetStatusReport() const;

  /**
   * @brief Retrieves the number of animals in the ecosystem.
   * @return The count of animals.
   */
  std::size_t GetCount() const noexcept;

private:
  std::vector<std::unique_ptr<animals::Animal>> animals_;  /// The collection of animals in the ecosystem.
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_ECOSYSTEM_H_