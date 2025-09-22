#include "payment_method.h"

#include <stdexcept>

PaymentMethod::PaymentMethod(const Date &operation_date, double price)
    : operation_date_(operation_date), price_(price) {
    if (price < 0.0) {
        throw std::invalid_argument("Negative price value");
    }
}

void PaymentMethod::SetPrice(double price) {
    if (price < 0.0) {
        throw std::invalid_argument("Negative price value");
    }

    price_ = price;
}

Date PaymentMethod::GetOperationDate() const noexcept {
    return operation_date_;
}

double PaymentMethod::GetPrice() const noexcept {
    return price_;
}