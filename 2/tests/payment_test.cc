#include <UnitTest++/UnitTest++.h>
#include <memory>
#include <stdexcept>

#include "staff/cashier.h"
#include "payment/context.h"
#include "payment/account.h"
#include "payment/ticket.h"
#include "payment/transaction.h"
#include "payment/payment_methods/cash_payment/cash_payment.h"
#include "payment/payment_methods/card_payment/card_payment.h"
#include "payment/payment_methods/card_payment/online_card_payment.h"
#include "utils/exceptions/payment_errors.h"

using namespace payment;
using namespace payment::payment_methods;
using namespace staff;
using namespace utils::exceptions;

struct PaymentFixture {
  PaymentFixture()
      : cashier("Alice", 1500.0),
        ticket(TicketCategory::kBase),
        context(std::make_shared<Account>("Aquarium", 10000.0)),
        visitor_account(std::make_shared<Account>("Test", 100.0)) {}

  Cashier cashier;
  Ticket ticket;
  PaymentContext context;
  std::shared_ptr<Account> visitor_account;
};

// Cash payment tests
TEST_FIXTURE(PaymentFixture, CashPaymentTransaction) {
  auto cash_method = std::make_unique<CashPayment>(context, ticket.GetPrice() + 5.0);
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(cash_method));

  cashier.ProcessTransaction(*transaction);

  CHECK_CLOSE(transaction->GetTotalAmount(), ticket.GetPrice(), 1e-6);
}

TEST_FIXTURE(PaymentFixture, InsufficientFundsCashPayment) {
  auto cash_method = std::make_unique<CashPayment>(context, ticket.GetPrice() - 1.0);
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(cash_method));

  CHECK_THROW(cashier.ProcessTransaction(*transaction), InsufficientFundsError);
}

// Card payment tests
TEST_FIXTURE(PaymentFixture, CardPaymentTransaction) {
  auto card_method = std::make_unique<CardPayment>(context, visitor_account);
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(card_method), visitor_account);

  cashier.ProcessTransaction(*transaction);

  CHECK_CLOSE(transaction->GetTotalAmount(), ticket.GetPrice(), 1e-6);
}

TEST_FIXTURE(PaymentFixture, InsufficientFundsCardPayment) {
  visitor_account->Withdraw(90.0);

  auto card_method = std::make_unique<CardPayment>(context, visitor_account);
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(card_method), visitor_account);

  CHECK_THROW(cashier.ProcessTransaction(*transaction), InsufficientFundsError);
}

// Online card payment tests
TEST_FIXTURE(PaymentFixture, OnlineCardPaymentTransaction) {
  auto online_card_method = std::make_unique<OnlineCardPayment>(context, visitor_account, "123");
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(online_card_method), visitor_account);

  cashier.ProcessTransaction(*transaction);

  CHECK_CLOSE(transaction->GetTotalAmount(), ticket.GetPrice(), 1e-6);
}

TEST_FIXTURE(PaymentFixture, InvalidCVVOnlineCardPayment) {
  CHECK_THROW(
      {
        auto online_card_method = std::make_unique<OnlineCardPayment>(context, visitor_account, "12A");
      },
      std::invalid_argument);
}

TEST_FIXTURE(PaymentFixture, InsufficientFundsOnlineCardPayment) {
  visitor_account->Withdraw(90.0);

  auto online_card_method = std::make_unique<OnlineCardPayment>(context, visitor_account, "123");
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(online_card_method), visitor_account);

  CHECK_THROW(cashier.ProcessTransaction(*transaction), InsufficientFundsError);
}

// Transaction tests
TEST_FIXTURE(PaymentFixture, TransactionCannotBeProcessedTwice) {
  auto cash_method = std::make_unique<CashPayment>(context, ticket.GetPrice() + 5.0);
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(cash_method));

  cashier.ProcessTransaction(*transaction);

  CHECK_THROW(cashier.ProcessTransaction(*transaction), TransactionAlreadyProcessedError);
}

int main(int argc, char** argv) {
  return UnitTest::RunAllTests();
}