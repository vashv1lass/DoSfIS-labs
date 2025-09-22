#include "cash_payment.h"

#include <iostream>
#include <stdexcept>

CashPayment::CashPayment(
    const Date &operation_date,
    double price,
    double amount_given
) : PaymentMethod(operation_date, price), amount_given_(amount_given) {
    if (amount_given < 0.0) {
        throw std::invalid_argument("Negative value of given amount");
    }
}

void CashPayment::Process() const {
    if (amount_given_ < price_) {
        // throw NotEnoughFundsException("Not enough cash provided");
    }

    std::cout << "Cash deposited: " << amount_given_ << " BYN.\nChange: "
              << amount_given_ - price_ << std::endl;
}

std::string CashPayment::GetPaymentMethod() const noexcept {
    return "Cash payment";
}