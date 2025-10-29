/**
 * @file animals/fish/shark.h
 * @brief Declaration of the Shark class.
 */

#ifndef ANIMALS_FISH_SHARK_H_
#define ANIMALS_FISH_SHARK_H_

#include "animals/fish/fish.h"

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @class Shark
 * @brief Derived class representing a shark, inheriting from Fish.
 */
class Shark : public Fish {
public:
  /**
   * @brief Implements the GetSpecies function for shark.
   * @return The species of the shark as a string.
   * @note Overrides the GetSpecies function from the Fish base class.
   */
  std::string GetSpecies() const noexcept override;

protected:
  /**
   * @brief Implements the Eat function for shark.
   * @note Overrides the Eat function from the Fish base class.
   * @note Accessible only to DiverFeeder staff.
   */
  void Eat() const noexcept override;
};

}  // namespace animals

#endif  // ANIMALS_FISH_SHARK_H_