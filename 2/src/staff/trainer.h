/**
 * @file staff/trainer.h
 * @brief Declaration of the Trainer class.
 */

#ifndef STAFF_TRAINER_H_
#define STAFF_TRAINER_H_

#include <string>

#include "animals/mammals/dolphin.h"
#include "animals/mammals/seal.h"
#include "staff/employee.h"

/**
 * @brief Namespace for all staff-related classes and functions.
 */
namespace staff {

/**
 * @class Trainer
 * @brief Derived class representing a trainer, inheriting from Employee.
 */
class Trainer : public Employee {
public:
  /**
   * @brief Constructor for Trainer class.
   * @param name The name of the trainer.
   * @param salary The salary of the trainer.
   */
  Trainer(std::string name, double salary);

  /**
   * @brief Retrieves the role of the trainer.
   * @return The role as a string ("Trainer").
   * @note Overrides the GetRole function from the Employee base class.
   */
  std::string GetRole() const noexcept override;

  /**
   * @brief Teaches a dolphin to draw.
   * @param dolphin Reference to the dolphin to teach.
   * @note This function accesses the protected LearnToDraw method of the dolphin.
   */
  void TeachDrawing(animals::Dolphin& dolphin);

  /**
   * @brief Teaches a seal to balance a ball.
   * @param seal Reference to the seal to teach.
   * @note This function accesses the protected LearnToBalanceBall method of the seal.
   */
  void TeachBallBalancing(animals::Seal& seal);
};

}  // namespace staff

#endif  // STAFF_TRAINER_H_