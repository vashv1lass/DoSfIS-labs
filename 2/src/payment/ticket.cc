#include "payment/ticket.h"

#include "utils/id_generator.h"
#include "utils/exceptions/unknown_type_errors.h"

namespace payment {

Ticket::Ticket(TicketCategory category) : category_(category), id_(utils::IDGenerator::Instance().NextID()) {
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
      throw utils::exceptions::UnknownTicketTypeError("Unknown ticket category.");
  }
}

TicketCategory Ticket::GetCategory() const noexcept {
  return category_;
}

double Ticket::GetPrice() const noexcept {
  return price_;
}

int Ticket::GetID() const noexcept {
  return id_;
}

std::string Ticket::GetInfo() const noexcept {
  switch (category_) {
    case TicketCategory::kBase:
      return "Base ticket for adults.";
    case TicketCategory::kVip:
      return "VIP ticket for adults.";
    case TicketCategory::kChildBase:
      return "Base ticket for children.";
    case TicketCategory::kChildVip:
      return "VIP ticket for children.";
    default:
      return "Unknown ticket.";
  }
}

}  // namespace payment