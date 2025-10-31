/** 
 * @file animals/animal.h
 * @brief Declaration of the Animal class.
 */

#ifndef ANIMALS_ANIMAL_H_
#define ANIMALS_ANIMAL_H_

#include <memory>
#include <stdexcept>
#include <string>

#include "animals/medical/medical.h"
#include "staff/diver_feeder.h"

// Forward declaration to avoid circular dependency.
namespace infrastructure {

class MedicalDepartment;

}  // namespace infrastructure

/**
 * @brief Namespace for all animal-related classes and functions.
 */
namespace animals {

/**
 * @class Animal
 * @brief Abstract base class representing a generic animal.
 */
class Animal {
public:
  /**
   * @brief Constructor for Animal class.
   * @param name The name of the animal.
   */
  explicit Animal(std::string name);
  
  /**
   * @brief Virtual destructor for Animal class.
   */
  virtual ~Animal() noexcept = default;

  /**
   * @brief Pure virtual function to imitate the animal movement.
   */
  virtual void Move() const noexcept = 0;
  
  /**
   * @brief Pure virtual function to get the species of the animal.
   * @return The species of the animal as a string.
   */
  virtual std::string GetSpecies() const noexcept = 0;
  
  /**
   * @brief Retrieves the name of the animal.
   * @return The name of the animal as a string.
   * @note The name is guaranteed to be non-empty.
   */
  const std::string& GetName() const noexcept;

protected:
  std::string name_;  /// The name of the animal.

  /**
   * @brief Pure virtual function to imitate the animal eating.
   * @note Accessible only to DiverFeeder staff.
   */
  virtual void Eat() const noexcept = 0;

  friend class staff::DiverFeeder;   // Allows DiverFeeder to access protected members.
};

}  // namespace animals

#endif  // ANIMALS_ANIMAL_H_