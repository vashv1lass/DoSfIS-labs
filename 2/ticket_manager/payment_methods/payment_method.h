#ifndef TICKET_MANAGER_PAYMENT_METHODS_PAYMENT_METHOD_H_
#define TICKET_MANAGER_PAYMENT_METHODS_PAYMENT_METHOD_H_

#include <string>

#include "utils/date.h"

class PaymentMethod {
public:
    PaymentMethod(const Date &operation_date = Date(), double price = -1.);

    virtual ~PaymentMethod() = default;

    void SetOperationDate(const Date &) noexcept;
    Date GetOperationDate() const noexcept;

    void SetPrice(double) noexcept;
    double GetPrice() const noexcept;

    virtual void Process() const = 0;
    virtual std::string GetPaymentMethod() const = 0;
protected:
    Date operation_date_;
    double price_;
};

#endif // TICKET_MANAGER_PAYMENT_METHODS_PAYMENT_METHOD_H_