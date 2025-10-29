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
   * @brief Pure virtual function to immitate the animal movement.
   */
  virtual void Move() const noexcept = 0;
  
  /**
   * @brief Pure virtual function to get the species of the animal.
   * @return The species of the animal as a string.
   */
  virtual std::string GetSpecies() const noexcept = 0;

  /**
   * @brief Assigns a medical record book to the animal.
   * @param record_book Shared pointer to the medical record book.
   * @throws std::invalid_argument if record_book is nullptr.
   */
  void AssignMedicalRecordBook(std::shared_ptr<medical::MedicalRecordBook> record_book);
  
  /**
   * @brief Retrieves the medical record book of the animal.
   * @return Shared pointer to the medical record book.
   * @note Returns nullptr if no medical record book is assigned.
   */
  std::shared_ptr<medical::MedicalRecordBook> GetMedicalRecordBook() const noexcept;

  /**
   * @brief Retrieves the name of the animal.
   * @return The name of the animal as a string.
   * @note The name is guaranteed to be non-empty.
   */
  const std::string& GetName() const noexcept;

protected:
  std::string name_;  /// The name of the animal.
  std::shared_ptr<medical::MedicalRecordBook> medical_record_book_;   /// The medical record book of the animal.

  /**
   * @brief Pure virtual function to immitate the animal eating.
   * @note Accessible only to DiverFeeder staff.
   */
  virtual void Eat() const noexcept = 0;

  friend class staff::DiverFeeder;   // Allows DiverFeeder to access protected members.
};

}  // namespace animals

#endif  // ANIMALS_ANIMAL_H_