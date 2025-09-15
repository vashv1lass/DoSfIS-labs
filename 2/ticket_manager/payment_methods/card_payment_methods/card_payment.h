#ifndef TICKET_MANAGER_PAYMENT_METHODS_CARD_PAYMENT_METHODS_CARD_PAYMENT_H
#define TICKET_MANAGER_PAYMENT_METHODS_CARD_PAYMENT_METHODS_CARD_PAYMENT_H

#include <string>

#include "ticket_manager/payment_methods/payment_method.h"

class CardPayment : public PaymentMethod {
public:
    CardPayment(
        const Date &operation_date, double price, double card_balance
    );

    ~CardPayment() override = default;

    void Process() const override;
    std::string GetPaymentMethod() const override;
protected:
    double card_balance_;
};

#endif // TICKET_MANAGER_PAYMENT_METHODS_CARD_PAYMENT_METHODS_CARD_PAYMENT_H