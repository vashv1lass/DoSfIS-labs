/**
 * @file infrastructure/maintenance.h
 * @brief Declaration of the MaintenanceUnit class.
 */

#ifndef INFRASTRUCTURE_MAINTENANCE_H_
#define INFRASTRUCTURE_MAINTENANCE_H_

#include <string>
#include <memory>
#include <unordered_map>

// Forward declaration of Tank
namespace infrastructure {

class Tank;

}  // namespace infrastructure

/**
 * @brief Namespace for all infrastructure-related classes and functions.
 */
namespace infrastructure {

/**
 * @class MaintenanceUnit
 * @brief Manages the maintenance tasks for the aquarium tanks.
 */
class MaintenanceUnit {
public:
  /**
   * @brief Default constructor for MaintenanceUnit class.
   */
  MaintenanceUnit() = default;

  /**
   * @brief Registers a tank with the maintenance unit.
   * @param tank Shared pointer to the tank to register.
   */
  void RegisterTank(std::shared_ptr<Tank> tank);

  /**
   * @brief Initiates the cleaning process for a tank by its ID.
   * @param id The ID of the tank to clean.
   */
  void CleanTank(int id);

private:
  std::unordered_map<int, std::shared_ptr<Tank>> tanks_;  /// Map of registered tanks by ID.

  /**
   * @brief Performs the actual cleaning operation on a tank.
   * @param tank Reference to the tank to clean.
   * @note This function carries out the detailed cleaning procedure.
   */
  void PerformCleaning(Tank& tank);
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_MAINTENANCE_H_