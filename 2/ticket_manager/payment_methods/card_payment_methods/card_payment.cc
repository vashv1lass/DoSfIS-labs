#include "card_payment.h"

#include <stdexcept>
#include <iostream>

CardPayment::CardPayment(
    const Date &operation_date, double price, double card_balance
) : PaymentMethod(operation_date, price), card_balance_(card_balance) {
    if (card_balance < 0.0) {
        throw std::out_of_range("Negative card balance value");
    }
}

void CardPayment::Process() {
    if (card_balance_ < price_) {
        // throw NotEnoughFundsException("Insufficient funds on card");
    }

    card_balance_ -= price_;

    std::cout << "Transaction approved. " << price_ << " BYN was debited.\n"
              << "Current balance: " << card_balance_ << " BYN." << std::endl;
}

void CardPayment::Refund() {
    card_balance_ += price_;

    std::cout << "Transaction approved. " << price_ << " BYN was credited.\n"
              << "Current balance: " << card_balance_ << " BYN." << std::endl;
}

std::string CardPayment::GetPaymentMethod() const noexcept {
    return "Card payment.";
}