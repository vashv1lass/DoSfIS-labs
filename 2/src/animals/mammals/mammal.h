/**
 * @file animals/mammals/mammal.h
 * @brief Declaration of the Mammal and SeaMammal classes.
 */

#ifndef ANIMALS_MAMMALS_MAMMAL_H_
#define ANIMALS_MAMMALS_MAMMAL_H_

#include "animals/animal.h"

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @class Mammal
 * @brief Derived class representing a mammal, inheriting from Animal.
 */
class Mammal : public Animal {
public:
  /**
   * @brief Constructor for Mammal class.
   * @param name The name of the mammal.
   * @param milk_production The milk production rate of the mammal.
   */
  Mammal(std::string name, double milk_production);

  /**
   * @brief Implements the Move function for mammal.
   * @note Overrides the Move function from the Animal base class.
   */
  void Move() const noexcept override;

  /**
   * @brief Implements the GetSpecies function for mammal.
   * @return The species of the mammal as a string.
   * @note Overrides the GetSpecies function from the Animal base class.
   */
  std::string GetSpecies() const noexcept override;

  /**
   * @brief Sets the milk production rate of the mammal.
   * @param milk_production The new milk production rate to set.
   */
  void SetMilkProduction(double milk_production);

  /**
   * @brief Retrieves the milk production rate of the mammal.
   * @return The milk production rate of the mammal.
   */
  double GetMilkProduction() const noexcept;

protected:
  double milk_production_;  /// The milk production rate of the mammal.

  /**
   * @brief Implements the Eat function for mammal.
   * @note Overrides the Eat function from the Animal base class.
   * @note Accessible only to DiverFeeder staff.
   */
  void Eat() const noexcept override;
};

/**
 * @class SeaMammal
 * @brief Derived class representing a sea mammal, inheriting from Mammal.
 */
class SeaMammal : public Mammal {
public:
  /**
   * @brief Constructor for SeaMammal class.
   * @param name The name of the sea mammal.
   * @param milk_production The milk production rate of the sea mammal.
   * @param dive_depth The maximum dive depth of the sea mammal.
   * @param breath_hold The breath hold time of the sea mammal.
   */
  SeaMammal(std::string name, double milk_production, double dive_depth,
            double breath_hold);

  /**
   * @brief Implements the Move function for sea mammal.
   * @note Overrides the Move function from the Mammal base class.
   */
  void Move() const noexcept override;

  /**
   * @brief Implements the GetSpecies function for sea mammal.
   * @return The species of the sea mammal as a string.
   * @note Overrides the GetSpecies function from the Mammal base class.
   */
  std::string GetSpecies() const noexcept override;

  /**
   * @brief Retrieves the maximum dive depth of the sea mammal.
   * @return The maximum dive depth of the sea mammal.
   */
  double GetDiveDepth() const noexcept;

  /**
   * @brief Retrieves the breath hold time of the sea mammal.
   * @return The breath hold time of the sea mammal.
   */
  double GetBreathHoldTime() const noexcept;

protected:
  double dive_depth_;  /// The maximum dive depth of the sea mammal.
  double breath_hold_time_;  /// The breath hold time of the sea mammal.
};

}  // namespace animals

#endif  // ANIMALS_MAMMALS_MAMMAL_H_