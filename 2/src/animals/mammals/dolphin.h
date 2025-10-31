/**
 * @file animals/mammals/dolphin.h
 * @brief Declaration of the Dolphin class.
 */

#ifndef ANIMALS_MAMMALS_DOLPHIN_H_
#define ANIMALS_MAMMALS_DOLPHIN_H_

#include "animals/mammals/mammal.h"

// Forward declaration of Trainer class in staff namespace
namespace staff {

class Trainer;

}  // namespace staff

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @class Dolphin
 * @brief Derived class representing a dolphin, inheriting from SeaMammal.
 */
class Dolphin : public SeaMammal {
public:
  /**
   * @brief Constructor for Dolphin class.
   * @param name The name of the dolphin.
   * @param milk_production The milk production rate of the dolphin.
   * @param dive_depth The maximum dive depth of the dolphin.
   * @param breath_hold The breath hold time of the dolphin.
   * @param iq The intelligence quotient of the dolphin.
   */
  Dolphin(std::string name, double milk_production, double dive_depth,
          double breath_hold, int iq);

  /**
   * @brief Implements the GetSpecies function for dolphin.
   * @return The species of the dolphin as a string.
   * @note Overrides the GetSpecies function from the SeaMammal base class.
   */
  std::string GetSpecies() const noexcept override;

  /**
   * @brief Retrieves the intelligence quotient of the dolphin.
   * @return The intelligence quotient of the dolphin.
   */
  int GetIQ() const noexcept;

  /**
   * @brief Checks if the dolphin can draw.
   * @return True if the dolphin can draw, false otherwise.
   */
  bool CanDraw() const noexcept;

  /**
   * @brief Makes the dolphin draw.
   * @note This function performs the drawing action.
   * @throws utils::exceptions::CannotPerformActionException if the dolphin
   *         has not learned to draw yet.
   */
  void Draw() const;

protected:
  /**
   * @brief Implements the Eat function for dolphin.
   * @note Overrides the Eat function from the SeaMammal base class.
   * @note Accessible only to DiverFeeder staff.
   */
  void Eat() const noexcept override;
  
private:
  int iq_;  /// The intelligence quotient of the dolphin.
  bool can_draw_;  /// Indicates whether the dolphin can draw.

  /**
   * @brief Makes the dolphin learn to draw.
   * @note This function trains the dolphin to acquire drawing ability.
   * @note Accessible only to Trainer staff.
   * @throws utils::exceptions::CannotPerformActionException if the dolphin's
   *         IQ is insufficient to learn drawing.
   */
  void LearnToDraw();

  friend class staff::Trainer;  // Allows Trainer to access private members.
};

}  // namespace animals

#endif  // ANIMALS_MAMMALS_DOLPHIN_H_