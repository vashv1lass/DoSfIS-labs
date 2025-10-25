#ifndef INFRASTRUCTURE_VISITOR_H_
#define INFRASTRUCTURE_VISITOR_H_

#include <string>
#include <vector>

#include "payment/ticket.h"

namespace infrastructure {

class Visitor {
public:
  explicit Visitor(std::string name, int age);

  const std::string& GetName() const noexcept;
  int GetAge() const noexcept;

  void AddTicket(payment::Ticket ticket);
  std::vector<payment::Ticket> GetTickets() const noexcept;

private:
  std::string name_;
  int age_;
  std::vector<payment::Ticket> tickets_;
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_VISITOR_H_