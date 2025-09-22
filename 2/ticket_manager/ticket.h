#ifndef TICKET_MANAGER_TICKET_H_
#define TICKET_MANAGER_TICKET_H_

#include <memory>

#include "tariffs/tariff.h"

class Ticket {
public:
    explicit Ticket(std::unique_ptr<Tariff>);

    int GetID() const noexcept;
    bool IsValid() const noexcept;
    std::unique_ptr<Tariff> GetTariff() const;

    void Invalidate() noexcept;
private:
    int id_;
    bool is_valid_;

    std::unique_ptr<Tariff> tariff_;
};

#endif // TICKET_MANAGER_TICKET_H_