#include "cashier.h"

#include <string>
#include <memory>
#include <optional>

#include "utils/date.h"
#include "ticket_manager/ticket.h"
#include "ticket_manager/ticket_manager.h"

Cashier::Cashier(
    const std::string &name, const Date &hire_date, double salary,
    double total_sales
) : Employee(name, hire_date, salary), total_sales_(total_sales) {}

double Cashier::GetTotalSales() const noexcept {
    return total_sales_;
}

std::optional<Ticket> Cashier::SellTicket(std::unique_ptr<Tariff> tariff, std::unique_ptr<PaymentMethod> payment_method) {
    TicketManager ticket_manager;
    
    std::optional<Ticket> ticket = ticket_manager.Purchase(std::move(tariff), std::move(payment_method));
    if (ticket) {
        total_sales_ += ticket->GetTariff()->GetPrice();
    }

    return ticket;
}

void Cashier::RefundTicket(Ticket &ticket, std::unique_ptr<PaymentMethod> payment_method) {
    TicketManager ticket_manager;

    ticket_manager.Refund(ticket, std::move(payment_method));

    total_sales_ -= ticket.GetTariff()->GetPrice();
}