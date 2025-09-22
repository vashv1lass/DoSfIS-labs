#include "ticket.h"

#include "utils/id_generator.h"

explicit Ticket::Ticket(std::unique_ptr<Tariff> tariff)
    : id_(IDGenerator::GenerateID()),
      tariff_(std::move(tariff)),
      is_valid_(true) {}

int Ticket::GetID() const noexcept {
    return id_;
}

bool Ticket::IsValid() const noexcept {
    return is_valid_;
}

std::unique_ptr<Tariff> Ticket::GetTariff() const {
    return tariff_->Clone();
}

void Ticket::Invalidate() noexcept {
    is_valid_ = false;
}