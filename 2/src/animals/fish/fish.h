/**
 * @file animals/fish/fish.h
 * @brief Declaration of the Fish class.
 */

#ifndef ANIMALS_FISH_FISH_H_
#define ANIMALS_FISH_FISH_H_

#include "animals/animal.h"

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @class Fish
 * @brief Derived class representing a fish, inheriting from Animal.
 */
class Fish : public Animal {
public:
  /**
   * @brief Constructor for Fish class.
   * @param name The name of the fish.
   * @param swim_speed The swimming speed of the fish.
   */
  Fish(std::string name, double swim_speed);

  /**
   * @brief Implements the Move function for fish.
   * @note Overrides the Move function from the Animal base class.
   */
  void Move() const noexcept override;

  /**
   * @brief Implements the GetSpecies function for fish.
   * @return The species of the fish as a string.
   * @note Overrides the GetSpecies function from the Animal base class.
   */
  std::string GetSpecies() const noexcept override;

  /**
   * @brief Retrieves the swimming speed of the fish.
   * @return The swimming speed of the fish.
   */
  double GetSwimSpeed() const noexcept;

  /**
   * @brief Sets the swimming speed of the fish.
   * @param speed The new swimming speed to set.
   */
  void SetSwimSpeed(double speed);

protected:
  double swim_speed_;  /// The swimming speed of the fish.

  /**
   * @brief Implements the Eat function for fish.
   * @note Overrides the Eat function from the Animal base class.
   * @note Accessible only to DiverFeeder staff.
   */
  void Eat() const noexcept override;
};

}  // namespace animals

#endif  // ANIMALS_FISH_FISH_H_