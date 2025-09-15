#include "card_payment.h"

#include <iostream>

CardPayment::CardPayment(
    const Date &operation_date, double price, double card_balance
) : PaymentMethod(operation_date, price), card_balance_(card_balance) {}

void CardPayment::Process() const {
    if (this->card_balance_ < this->price_) {
        // throw NotEnoughFundsException
    }

    std::cout << "Transaction approved. " << this->price_ << "BYN was debited.\n" <<
        "Current balance: " << this->card_balance_ << "BYN." << std::endl;
}

std::string CardPayment::GetPaymentMethod() const {
    return "Card payment.";
}