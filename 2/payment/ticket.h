#ifndef PAYMENT_TICKET_MANAGER_TICKET_H_
#define PAYMENT_TICKET_MANAGER_TICKET_H_

#include <string>
#include <stdexcept>

namespace payment {

enum class TicketCategory {
  kBase,
  kVip,
  kChildBase,
  kChildVip
};

class Ticket {
public:
  explicit Ticket(TicketCategory category);

  TicketCategory GetCategory() const noexcept;
  double GetPrice() const noexcept;
  std::string GetInfo() const noexcept;

private:
  TicketCategory category_;
  double price_;
};

}  // namespace payment

#endif  // PAYMENT_TICKET_MANAGER_TICKET_H_