#include "online_card_payment.h"

#include <chrono>

OnlineCardPayment::OnlineCardPayment(
    const Date &operation_date, double price, double card_balance,
    const std::string &card_number, const std::string &security_code
) : CardPayment(operation_date, price, card_balance),
    card_number_(card_number), security_code_(security_code) {}

void OnlineCardPayment::Process() const {
    if (card_number_.length() != 16 || security_code_.length() != 3) {
        // throw InvalidCardDataException
    }

    if (this->card_balance_ < this->price_) {
        // throw NotEnoughFundsException
    }

    std::cout << "Transaction approved. " << this->price_ << "BYN was debited.\n" <<
        "Current balance: " << this->card_balance_ << "BYN." << std::endl;
}

std::string OnlineCardPayment::GetPaymentMethod() const {
    return "Online card payment";
}
