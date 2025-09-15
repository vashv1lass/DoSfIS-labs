#ifndef TICKET_MANAGER_PAYMENT_METHODS_CARD_PAYMENT_METHODS_ONLINE_CARD_PAYMENT_H_
#define TICKET_MANAGER_PAYMENT_METHODS_CARD_PAYMENT_METHODS_ONLINE_CARD_PAYMENT_H_

#include "card_payment.h"

class OnlineCardPayment : public CardPayment {
public:
    OnlineCardPayment(
        const Date &, double, double, const std::string &, const std::string &
    );

    ~OnlineCardPayment() override = default;

    void Process() const override;
    std::string GetPaymentMethod() const override;
private:
    std::string card_number_;
    std::string security_code_;
};

#endif // TICKET_MANAGER_PAYMENT_METHODS_CARD_PAYMENT_METHODS_ONLINE_CARD_PAYMENT_H_