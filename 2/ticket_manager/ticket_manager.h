#ifndef TICKET_MANAGER_TICKET_MANAGER_H_
#define TICKET_MANAGER_TICKET_MANAGER_H_

#include <optional>

#include "ticket.h"
#include "payment_methods/payment_method.h"
#include "customer/customer.h"

class TicketManager {
public:
    std::optional<Ticket> Purchase(
        std::unique_ptr<Tariff> tariff,
        std::unique_ptr<PaymentMethod> payment_methodx
    );
};

#endif // TICKET_MANAGER_TICKET_MANAGER_H_