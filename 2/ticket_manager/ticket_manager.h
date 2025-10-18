#ifndef TICKET_MANAGER_TICKET_MANAGER_H_
#define TICKET_MANAGER_TICKET_MANAGER_H_

#include <optional>
#include <memory>

#include "ticket.h"
#include "payment_methods/payment_method.h"

class TicketManager {
public:
    std::optional<Ticket> Purchase(
        std::unique_ptr<Tariff>,
        std::unique_ptr<PaymentMethod>
    );

    void Refund(const Ticket &, std::unique_ptr<PaymentMethod>);
};

#endif // TICKET_MANAGER_TICKET_MANAGER_H_