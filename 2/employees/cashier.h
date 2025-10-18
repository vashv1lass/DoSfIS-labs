#ifndef EMPLOYEE_CASHIER_H_
#define EMPLOYEE_CASHIER_H_

#include <string>
#include <optional>

#include "employee.h"
#include "utils/date.h"
#include "ticket_manager/ticket.h"
#include "ticket_manager/tariffs/tariff.h"
#include "ticket_manager/payment_methods/payment_method.h"

class Cashier : public Employee {
public:
    Cashier(const std::string &, const Date &, double, double);
    
    double GetTotalSales() const noexcept;

    std::optional<Ticket> SellTicket(std::unique_ptr<Tariff>, std::unique_ptr<PaymentMethod>);
    void RefundTicket(Ticket &, std::unique_ptr<PaymentMethod>);
private:
    double total_sales_;
};

#endif // EMPLOYEE_CASHIER_H_