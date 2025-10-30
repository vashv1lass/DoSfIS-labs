/**
 * @file infrastructure/tank.h
 * @brief Declaration of the Tank class.
 */

#ifndef INFRASTRUCTURE_TANK_H_
#define INFRASTRUCTURE_TANK_H_

#include <memory>
#include <stdexcept>
#include <vector>

#include "animals/animal.h"

/**
 * @brief Namespace for all infrastructure-related classes and functions.
 */
namespace infrastructure {

/**
 * @class Tank
 * @brief Represents a tank in the aquarium, containing animals and managing its state.
 */
class Tank {
public:
  /**
   * @brief Constructor for Tank class.
   * @param depth The depth of the tank.
   * @param volume The volume of the tank.
   */
  Tank(double depth, double volume);

  /**
   * @brief Adds an animal to the tank.
   * @param animal Shared pointer to the animal to add.
   * @throws std::invalid_argument if animal is nullptr.
   */
  void AddAnimal(std::shared_ptr<animals::Animal> animal);

  /**
   * @brief Displays information about all animals in the tank.
   * @note This function prints the details of each animal to the standard output.
   */
  void ShowAll() const noexcept;

  /**
   * @brief Retrieves the ID of the tank.
   * @return The ID of the tank.
   */
  int GetID() const noexcept;

  /**
   * @brief Retrieves the depth of the tank.
   * @return The depth of the tank.
   */
  double GetDepth() const noexcept;

  /**
   * @brief Retrieves the volume of the tank.
   * @return The volume of the tank.
   */
  double GetVolume() const noexcept;

  /**
   * @brief Checks if the tank is clean.
   * @return True if the tank is clean, false otherwise.
   */
  bool IsClean() const noexcept;

  /**
   * @brief Sets the depth of the tank.
   * @param depth The new depth to set.
   */
  void SetDepth(double depth);

  /**
   * @brief Sets the volume of the tank.
   * @param volume The new volume to set.
   */
  void SetVolume(double volume);

  /**
   * @brief Marks the tank as clean.
   * @note This function updates the internal state of the tank.
   */
  void MarkClean() noexcept;

  /**
   * @brief Marks the tank as dirty.
   * @note This function updates the internal state of the tank.
   */
  void MarkDirty() noexcept;

private:
  int id_;  /// The ID of the tank.

  double depth_;  /// The depth of the tank.
  double volume_;  /// The volume of the tank.

  bool is_clean_;  /// Indicates whether the tank is clean.
  
  std::vector<std::shared_ptr<animals::Animal>> animals_;  /// The collection of animals in the tank.
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_TANK_H_