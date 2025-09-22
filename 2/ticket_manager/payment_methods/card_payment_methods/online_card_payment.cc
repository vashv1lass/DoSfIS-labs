#include "online_card_payment.h"

#include <cctype>
#include <stdexcept>
#include <iostream>

OnlineCardPayment::OnlineCardPayment(
    const Date &operation_date,
    double price,
    double card_balance,
    const std::string &card_number,
    const std::string &security_code
) : CardPayment(operation_date, price, card_balance),
    card_number_(card_number), security_code_(security_code) {
    if (card_number.length() == 16) {
        for (auto current_card_number_digit : card_number) {
            if (!isdigit(current_card_number_digit)) {
                throw std::invalid_argument(
                    "Unexpected non-digit character in card number"
                );
            }
        }
    } else {
        throw std::invalid_argument("Invalid card number");
    }

    if (security_code.length() == 3) {
        for (auto current_security_code_digit : security_code_) {
            if (!isdigit(current_security_code_digit)) {
                throw std::invalid_argument(
                    "Unexpected non-digit character in secuirity code"
                );
            }
        }
    } else {
        throw std::invalid_argument("Invalid security code");
    }
}

void OnlineCardPayment::Process() const {
    if (card_balance_ < price_) {
        // throw NotEnoughFundsException("Insufficient funds on card");
    }

    std::cout << "Online transaction approved. " << price_
              << "BYN was debited.\nCurrent balance: " << card_balance_
              << "BYN." << std::endl;
}

std::string OnlineCardPayment::GetPaymentMethod() const {
    return "Online card payment";
}