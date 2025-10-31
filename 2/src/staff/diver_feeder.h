/**
 * @file staff/diver_feeder.h
 * @brief Declaration of the DiverFeeder class.
 */

#ifndef STAFF_DIVER_FEEDER_H_
#define STAFF_DIVER_FEEDER_H_

#include <iostream>
#include <string>

#include "staff/employee.h"

// Forward declaration of Animal class in animals namespace
namespace animals {

class Animal;

}  // namespace animals

/**
 * @brief Namespace for all staff-related classes and functions.
 */
namespace staff {

/**
 * @class DiverFeeder
 * @brief Derived class representing a diver feeder, inheriting from Employee.
 */
class DiverFeeder : public Employee {
public:
  /**
   * @brief Constructor for DiverFeeder class.
   * @param name The name of the diver feeder.
   * @param salary The salary of the diver feeder.
   * @param oxygen_tank_volume The volume of the oxygen tank used by the diver feeder.
   */
  DiverFeeder(std::string name, double salary, double oxygen_tank_volume);

  /**
   * @brief Retrieves the role of the diver feeder.
   * @return The role as a string ("DiverFeeder").
   * @note Overrides the GetRole function from the Employee base class.
   */
  std::string GetRole() const noexcept override;
  
  /**
   * @brief Retrieves the volume of the oxygen tank.
   * @return The volume of the oxygen tank.
   */
  double GetOxygenTankVolume() const noexcept;

  /**
   * @brief Feeds an animal.
   * @param animal Reference to the animal to feed.
   * @note This function accesses the protected Eat method of the animal.
   */
  void Feed(animals::Animal& animal);

private:
  double oxygen_tank_volume_;  /// The volume of the oxygen tank used by the diver feeder.
};

}  // namespace staff

#endif  // STAFF_DIVER_FEEDER_H_