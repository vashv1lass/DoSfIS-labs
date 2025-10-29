/**
 * @file animals/fish/stingray.h
 * @brief Declaration of the Stingray class.
 */

#ifndef ANIMALS_FISH_STINGRAY_H_
#define ANIMALS_FISH_STINGRAY_H_

#include "animals/fish/fish.h"

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @class Stingray
 * @brief Derived class representing a stingray, inheriting from Fish.
 */
class Stingray : public Fish {
public:
  /**
   * @brief Constructor for Stingray class.
   * @param name The name of the stingray.
   * @param swim_speed The swimming speed of the stingray.
   * @param venomous Indicates whether the stingray is venomous.
   * @param fin_span The span of the stingray's fins.
   */
  Stingray(std::string name, double swim_speed, bool venomous,
           double fin_span);

  /**
   * @brief Implements the Move function for stingray.
   * @note Overrides the Move function from the Fish base class.
   */
  void Move() const noexcept override;

  /**
   * @brief Implements the GetSpecies function for stingray.
   * @return The species of the stingray as a string.
   * @note Overrides the GetSpecies function from the Fish base class.
   */
  std::string GetSpecies() const noexcept override;

  /**
   * @brief Checks if the stingray is venomous.
   * @return True if the stingray is venomous, false otherwise.
   */
  bool IsVenomous() const noexcept;

  /**
   * @brief Sets the fin span of the stingray.
   * @param fin_span The new fin span to set.
   */
  void SetFinSpan(double fin_span);

  /**
   * @brief Retrieves the fin span of the stingray.
   * @return The fin span of the stingray.
   */
  double GetFinSpan() const;

private:
  bool venomous_;  /// Indicates whether the stingray is venomous.
  double fin_span_;  /// The span of the stingray's fins.
};

}  // namespace animals

#endif  // ANIMALS_FISH_STINGRAY_H_