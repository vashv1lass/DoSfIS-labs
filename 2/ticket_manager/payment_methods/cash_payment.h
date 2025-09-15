#ifndef TICKET_MANAGER_CASH_PAYMENT_H_
#define TICKET_MANAGER_CASH_PAYMENT_H_

#include "payment_method.h"

class CashPayment : public PaymentMethod {
public:
    CashPayment(
        const Date &operation_date = Date(),
        double price = -1.,
        double amount_given = -1.
    ) noexcept;

    void Process() const override;
    std::string GetPaymentMethod() const override;
private:
    double amount_given_;
};

#endif // TICKET_MANAGER_CASH_PAYMENT_H_