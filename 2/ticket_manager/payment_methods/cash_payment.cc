#include "cash_payment.h"

#include <iostream>
#include <stdexcept>

CashPayment::CashPayment(
    const Date &operation_date,
    double price,
    double amount_given
) : PaymentMethod(operation_date, price), amount_given_(amount_given) {
    if (amount_given < 0.0) {
        throw std::out_of_range("Negative value of given amount");
    }
}

void CashPayment::Process() {
    if (amount_given_ < price_) {
        // throw NotEnoughFundsException("Not enough cash provided");
    }

    std::cout << "Cash deposited: " << amount_given_ << " BYN.\nChange: "
              << amount_given_ - price_ << std::endl;
}

void CashPayment::Refund() {
    std::cout << "Cash refunded: " << price_ << " BYN." << std::endl;
}

std::string CashPayment::GetPaymentMethod() const noexcept {
    return "Cash payment";
}