#ifndef TICKET_MANAGER_PAYMENT_METHODS_PAYMENT_METHOD_H_
#define TICKET_MANAGER_PAYMENT_METHODS_PAYMENT_METHOD_H_

#include <string>

#include "utils/date.h"

class PaymentMethod {
public:
    PaymentMethod(const Date &, double);

    virtual ~PaymentMethod() = default;

    void SetPrice(double) noexcept;

    Date GetOperationDate() const noexcept;
    double GetPrice() const noexcept;

    virtual std::string GetPaymentMethod() const noexcept = 0;

    virtual void Process() = 0;
    virtual void Refund() = 0;
protected:
    Date operation_date_;
    double price_;
};

#endif // TICKET_MANAGER_PAYMENT_METHODS_PAYMENT_METHOD_H_