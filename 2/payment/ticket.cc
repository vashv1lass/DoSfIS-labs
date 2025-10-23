#include "payment/ticket.h"

namespace payment {

Ticket::Ticket(TicketCategory category) : category_(category) {
  switch (category_) {
    case TicketCategory::kBase:
      price_ = 25.0;
      break;
    case TicketCategory::kVip:
      price_ = 50.0;
      break;
    case TicketCategory::kChildBase:
      price_ = 15.0;
      break;
    case TicketCategory::kChildVip:
      price_ = 30.0;
      break;
    default:
      throw std::invalid_argument("Unknown ticket category.");
  }
}

TicketCategory Ticket::GetCategory() const noexcept {
  return category_;
}

double Ticket::GetPrice() const noexcept {
  return price_;
}

std::string Ticket::GetInfo() const noexcept {
  switch (category_) {
    case TicketCategory::kBase:
      return "Base ticket for adults.";
    case TicketCategory::kVip:
      return "VIP ticket for adults with special access.";
    case TicketCategory::kChildBase:
      return "Child ticket (base).";
    case TicketCategory::kChildVip:
      return "Child VIP ticket with extra perks.";
    default:
      return "Unknown ticket.";
  }
}

}  // namespace payment