#include "cash_payment.h"

#include <iostream>
#include <mutex>
#include <ostream>

CashPayment::CashPayment(
        const Date &operation_date,
        double price,
        double amount_given
) noexcept : PaymentMethod(operation_date, price), amount_given_(amount_given) {}

void CashPayment::Process() const {
    if (this->amount_given_ < this->price_) {
        // throw NotEnoughFundsException
    }

    std::cout << "Cash deposited: " << this->amount_given_ << " BYN.\n" <<
        "Сдача: " << this->price_ - this->amount_given_ << std::endl;
}

std::string CashPayment::GetPaymentMethod() const {
    return "Cash payment";
}