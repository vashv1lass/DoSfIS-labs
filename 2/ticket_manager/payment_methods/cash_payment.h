#ifndef TICKET_MANAGER_CASH_PAYMENT_H_
#define TICKET_MANAGER_CASH_PAYMENT_H_

#include <string>

#include "payment_method.h"

class CashPayment : public PaymentMethod {
public:
    CashPayment(const Date &, double, double);

    std::string GetPaymentMethod() const noexcept override;

    void Process() override;
    void Refund() override;
private:
    double amount_given_;
};

#endif // TICKET_MANAGER_CASH_PAYMENT_H_