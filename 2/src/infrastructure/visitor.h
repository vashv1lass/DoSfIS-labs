/**
 * @file infrastructure/visitor.h
 * @brief Declaration of the Visitor class.
 */

#ifndef INFRASTRUCTURE_VISITOR_H_
#define INFRASTRUCTURE_VISITOR_H_

#include <string>
#include <vector>

#include "payment/ticket.h"

/**
 * @brief Namespace for all infrastructure-related classes and functions.
 */
namespace infrastructure {

/**
 * @class Visitor
 * @brief Represents a visitor to the aquarium.
 */
class Visitor {
public:
  /**
   * @brief Constructor for Visitor class.
   * @param name The name of the visitor.
   * @param age The age of the visitor.
   */
  explicit Visitor(std::string name, int age);

  /**
   * @brief Retrieves the name of the visitor.
   * @return The name of the visitor as a string.
   */
  const std::string& GetName() const noexcept;

  /**
   * @brief Retrieves the age of the visitor.
   * @return The age of the visitor.
   */
  int GetAge() const noexcept;

  /**
   * @brief Adds a ticket to the visitor's collection.
   * @param ticket The ticket to add.
   */
  void AddTicket(payment::Ticket ticket);

  /**
   * @brief Retrieves all tickets held by the visitor.
   * @return A vector containing all the visitor's tickets.
   */
  std::vector<payment::Ticket> GetTickets() const noexcept;

private:
  std::string name_;  /// The name of the visitor.
  int age_;           /// The age of the visitor.
  std::vector<payment::Ticket> tickets_;  /// The collection of tickets held by the visitor.
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_VISITOR_H_