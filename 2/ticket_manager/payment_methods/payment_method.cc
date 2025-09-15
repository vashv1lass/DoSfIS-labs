#include "payment_method.h"

PaymentMethod::PaymentMethod(const Date &operation_date, double price) {
    this->operation_date_ = operation_date;
    this->price_ = price;
}

void PaymentMethod::SetOperationDate(const Date &operation_date) noexcept {
    this->operation_date_ = operation_date;
}

Date PaymentMethod::GetOperationDate() const noexcept {
    return this->operation_date_;
}

void PaymentMethod::SetPrice(double price) noexcept {
    this->price_ = price;
}

double PaymentMethod::GetPrice() const noexcept {
    return this->price_;
}