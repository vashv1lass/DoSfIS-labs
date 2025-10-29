/**
 * @file animals/reptile/sea_turtle.h
 * @brief Declaration of the SeaTurtle class.
 */

#ifndef ANIMALS_REPTILE_SEA_TURTLE_H_
#define ANIMALS_REPTILE_SEA_TURTLE_H_

#include "animals/reptile/reptile.h"

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @class SeaTurtle
 * @brief Derived class representing a sea turtle, inheriting from Reptile.
 */
class SeaTurtle : public Reptile {
public:
  /**
   * @brief Constructor for SeaTurtle class.
   * @param name The name of the sea turtle.
   * @param body_temperature The body temperature of the sea turtle.
   * @param shell_diameter The diameter of the sea turtle's shell.
   */
  SeaTurtle(std::string name, double body_temperature,
            double shell_diameter);

  /**
   * @brief Implements the Move function for sea turtle.
   * @note Overrides the Move function from the Reptile base class.
   */
  void Move() const noexcept override;
  
  /**
   * @brief Implements the GetSpecies function for sea turtle.
   * @return The species of the sea turtle as a string.
   * @note Overrides the GetSpecies function from the Reptile base class.
   */
  std::string GetSpecies() const noexcept override;

  /**
   * @brief Retrieves the diameter of the sea turtle's shell.
   * @return The diameter of the sea turtle's shell.
   */
  double GetShellDiameter() const noexcept;

private:
  double shell_diameter_;  /// The diameter of the sea turtle's shell.
};

}  // namespace animals

#endif  // ANIMALS_REPTILE_SEA_TURTLE_H_