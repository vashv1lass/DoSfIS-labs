/**
 * @file animals/reptile/reptile.h
 * @brief Declaration of the Reptile class.
 */

#ifndef ANIMALS_REPTILE_REPTILE_H_
#define ANIMALS_REPTILE_REPTILE_H_

#include "animals/animal.h"

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @class Reptile
 * @brief Derived class representing a reptile, inheriting from Animal.
 */
class Reptile : public Animal {
public:
  /**
   * @brief Constructor for Reptile class.
   * @param name The name of the reptile.
   * @param body_temperature The body temperature of the reptile.
   */
  Reptile(std::string name, double body_temperature);

  /**
   * @brief Implements the Move function for reptile.
   * @note Overrides the Move function from the Animal base class.
   */
  void Move() const noexcept override;

  /**
   * @brief Implements the GetSpecies function for reptile.
   * @return The species of the reptile as a string.
   * @note Overrides the GetSpecies function from the Animal base class.
   */
  std::string GetSpecies() const noexcept override;

  /**
   * @brief Sets the body temperature of the reptile.
   * @param temperature The new body temperature to set.
   */
  void SetBodyTemperature(double temperature);

  /**
   * @brief Retrieves the body temperature of the reptile.
   * @return The body temperature of the reptile.
   */
  double GetBodyTemperature() const noexcept;

protected:
  double body_temperature_;  /// The body temperature of the reptile.

  /**
   * @brief Implements the Eat function for reptile.
   * @note Overrides the Eat function from the Animal base class.
   * @note Accessible only to DiverFeeder staff.
   */
  void Eat() const noexcept override;
};

}  // namespace animals

#endif  // ANIMALS_REPTILE_REPTILE_H_