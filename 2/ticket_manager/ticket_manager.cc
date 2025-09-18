#include "ticket_manager.h"

#include <iostream>

std::optional<Ticket> TicketManager::Purchase(
    std::unique_ptr<Tariff> tariff,
    std::unique_ptr<PaymentMethod> payment_method
) {
    Ticket ticket(std::move(tariff));
    
    try {
        std::cout << "Purchasing a ticket.\n"
                     "Tariff: " << ticket.GetTariff()->GetTariffType() <<
                     " Price: " << ticket.GetTariff()->GetPrice() << " BYN\n";
        
        payment_method->SetPrice(ticket.GetTariff()->GetPrice());
        payment_method->Process();

        std::cout << "Ticket " << ticket.GetID() << " was successfully "
                     "purchased!\n";

        return ticket;
    } catch (const std::exception &e) {
        std::cerr << "Payment process error: " << e.what() << "\n\n";
        ticket.Invalidate();

        return std::nullopt;
    }
}