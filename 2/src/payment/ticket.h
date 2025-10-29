/**
 * @file payment/ticket.h
 * @brief Declaration of the Ticket class and TicketCategory enum.
 */

#ifndef PAYMENT_TICKET_H_
#define PAYMENT_TICKET_H_

#include <string>

/**
 * @brief Namespace for payment-related classes and functions.
 */
namespace payment {

/**
 * @enum TicketCategory
 * @brief Enumerates the possible ticket categories.
 */
enum class TicketCategory {
  kBase,      /// Base category ticket.
  kVip,       /// VIP category ticket.
  kChildBase, /// Base category ticket for children.
  kChildVip   /// VIP category ticket for children.
};

/**
 * @class Ticket
 * @brief Represents a ticket with a category and price.
 */
class Ticket {
public:
  /**
   * @brief Constructor for Ticket class.
   * @param category The category of the ticket.
   * @throws std::invalid_argument if the category is unknown.
   */
  explicit Ticket(TicketCategory category);

  /**
   * @brief Retrieves the category of the ticket.
   * @return The category of the ticket.
   */
  TicketCategory GetCategory() const noexcept;

  /**
   * @brief Retrieves the price of the ticket.
   * @return The price of the ticket.
   */
  double GetPrice() const noexcept;

  /**
   * @brief Retrieves information about the ticket.
   * @return A string containing information about the ticket.
   */
  std::string GetInfo() const noexcept;

private:
  TicketCategory category_;  /// The category of the ticket.
  double price_;             /// The price of the ticket.
};

}  // namespace payment

#endif  // PAYMENT_TICKET_MANAGER_TICKET_H_