/**
 * @file animals/mammals/seal.h
 * @brief Declaration of the Seal class.
 */

#ifndef ANIMALS_MAMMALS_SEAL_H_
#define ANIMALS_MAMMALS_SEAL_H_

#include "animals/mammals/mammal.h"
#include "staff/trainer.h"

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @class Seal
 * @brief Derived class representing a seal, inheriting from SeaMammal.
 */
class Seal : public SeaMammal {
public:
  /**
   * @brief Constructor for Seal class.
   * @param name The name of the seal.
   * @param milk_production The milk production rate of the seal.
   * @param dive_depth The maximum dive depth of the seal.
   * @param breath_hold The breath hold time of the seal.
   */
  Seal(std::string name, double milk_production, double dive_depth,
       double breath_hold);

  /**
   * @brief Implements the GetSpecies function for seal.
   * @return The species of the seal as a string.
   * @note Overrides the GetSpecies function from the SeaMammal base class.
   */
  std::string GetSpecies() const noexcept override;

  /**
   * @brief Checks if the seal can balance a ball.
   * @return True if the seal can balance a ball, false otherwise.
   */
  bool CanBalanceBall() const noexcept;

  /**
   * @brief Makes the seal balance a ball.
   * @note This function performs the ball balancing action.
   */
  void BalanceBall() const noexcept;

protected:
  /**
   * @brief Implements the Eat function for seal.
   * @note Overrides the Eat function from the SeaMammal base class.
   * @note Accessible only to DiverFeeder staff.
   */
  void Eat() const noexcept override;
  
private:
  bool can_balance_ball_;  /// Indicates whether the seal can balance a ball.

  /**
   * @brief Makes the seal learn to balance a ball.
   * @note This function trains the seal to acquire ball balancing ability.
   * @note Accessible only to Trainer staff.
   */
  void LearnToBalanceBall() noexcept;

  friend class staff::Trainer;  /// Allows Trainer to access private members.
};

}  // namespace animals

#endif  // ANIMALS_MAMMALS_SEAL_H_