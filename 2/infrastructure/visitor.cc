#include "infrastructure/visitor.h"

namespace infrastructure {

Visitor::Visitor(std::string name, int age) : name_(std::move(name)), age_(age) {
  if (name_.empty()) {
    throw std::invalid_argument("Visitor name cannot be empty.");
  }
  if (age_ < 0) {
    throw std::out_of_range("Visitor age cannot be negative.");
  }
}

const std::string& Visitor::GetName() const noexcept { return name_; }

int Visitor::GetAge() const noexcept { return age_; }

void Visitor::AddTicket(payment::Ticket ticket) { tickets_.push_back(std::move(ticket)); }

std::vector<payment::Ticket> Visitor::GetTickets() const noexcept { return tickets_; }

}  // namespace infrastructure