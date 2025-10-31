#ifndef PAYMENT_TEST_CC_
#define PAYMENT_TEST_CC_

#include <UnitTest++/UnitTest++.h>

#include <memory>
#include <stdexcept>

#include "payment/payment.h"
#include "staff/staff.h"
#include "utils/utils.h"

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

// Account tests
TEST(AccountCreation) {
  Account account("Test", 50.0);
  CHECK_EQUAL("Test", account.GetOwner());
  CHECK_CLOSE(50.0, account.GetBalance(), 1e-6);
  CHECK_THROW(Account("", 50.0), std::invalid_argument);
  CHECK_THROW(Account("Test", -10.0), std::out_of_range);
}

TEST(AccountDeposit) {
  Account account("Test", 0.0);
  account.Deposit(13.0);
  CHECK_CLOSE(account.GetBalance(), 13.0, 1e-6);
  CHECK_THROW(account.Deposit(-5.0), std::invalid_argument);
}

TEST(AccountWithdraw) {
  Account account("Test", 10.0);
  account.Withdraw(5.0);
  CHECK_CLOSE(account.GetBalance(), 5.0, 1e-6);
  CHECK_THROW(account.Withdraw(-10.0), std::invalid_argument);
  CHECK_THROW(account.Withdraw(10.0), InsufficientFundsError);
}

TEST(AccountHasEnough) {
  Account account("Test", 20.0);
  CHECK(account.HasEnough(15.0));
  CHECK(!account.HasEnough(25.0));
}

// Context tests
TEST(PaymentContextCreation) {
  auto aquarium_account = std::make_shared<Account>("Aquarium", 5000.0);
  PaymentContext context(aquarium_account);
  CHECK_EQUAL("Aquarium", context.GetAquariumAccount().GetOwner());
  CHECK_THROW(PaymentContext(nullptr), std::invalid_argument);
}

TEST(PaymentContextGetAquariumAccount) {
  auto aquarium_account = std::make_shared<Account>("Aquarium", 5000.0);

  PaymentContext context(aquarium_account);
  Account& account = context.GetAquariumAccount();
  CHECK_EQUAL("Aquarium", account.GetOwner());
  CHECK_CLOSE(5000.0, account.GetBalance(), 1e-6);

  const PaymentContext& const_context = context;
  const Account& const_account = const_context.GetAquariumAccount();
  CHECK_EQUAL("Aquarium", const_account.GetOwner());
  CHECK_CLOSE(5000.0, const_account.GetBalance(), 1e-6);
}

// Card payment tests
TEST_FIXTURE(PaymentFixture, CardPaymentTransaction) {
  auto card_method = std::make_unique<CardPayment>(context, visitor_account);
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(card_method), visitor_account);

  cashier.ProcessTransaction(*transaction);

  CHECK_CLOSE(transaction->GetTotalAmount(), ticket.GetPrice(), 1e-6);
}

TEST_FIXTURE(PaymentFixture, CardPaymentMethodInfo) {
  auto card_method = std::make_unique<CardPayment>(context, visitor_account);
  CHECK_EQUAL("Card payment (POS)", card_method->GetPaymentMethodInfo());
}

TEST_FIXTURE(PaymentFixture, InvalidCardPaymentAccount) {
  CHECK_THROW(
      {
        auto card_method = std::make_unique<CardPayment>(context, nullptr);
      },
      std::invalid_argument);
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

TEST_FIXTURE(PaymentFixture, OnlineCardPaymentMethodInfo) {
  auto online_card_method = std::make_unique<OnlineCardPayment>(context, visitor_account, "123");
  CHECK_EQUAL("Online card payment", online_card_method->GetPaymentMethodInfo());
}

TEST_FIXTURE(PaymentFixture, InvalidOnlineCardPaymentAccount) {
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

// Cash payment tests
TEST_FIXTURE(PaymentFixture, CashPaymentTransaction) {
  auto cash_method = std::make_unique<CashPayment>(context, ticket.GetPrice() + 5.0);
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(cash_method));

  cashier.ProcessTransaction(*transaction);

  CHECK_CLOSE(transaction->GetTotalAmount(), ticket.GetPrice(), 1e-6);
}

TEST_FIXTURE(PaymentFixture, CashPaymentMethodInfo) {
  auto cash_method = std::make_unique<CashPayment>(context, ticket.GetPrice() + 5.0);
  CHECK_EQUAL("Cash payment", cash_method->GetPaymentMethodInfo());
}

TEST_FIXTURE(PaymentFixture, InvalidCashPaymentAmount) {
  CHECK_THROW(
      {
        auto cash_method = std::make_unique<CashPayment>(context, -10.0);
      },
      std::out_of_range);
}

TEST_FIXTURE(PaymentFixture, InsufficientFundsCashPayment) {
  auto cash_method = std::make_unique<CashPayment>(context, ticket.GetPrice() - 1.0);
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(cash_method));

  CHECK_THROW(cashier.ProcessTransaction(*transaction), InsufficientFundsError);
}

// Ticket tests
TEST(BaseTicketCreation) {
  Ticket base_ticket(TicketCategory::kBase);
  CHECK(TicketCategory::kBase == base_ticket.GetCategory());
  CHECK_CLOSE(25.0, base_ticket.GetPrice(), 1e-6);
  CHECK_EQUAL("Base ticket for adults.", base_ticket.GetInfo());
}

TEST(VipTicketCreation) {
  Ticket vip_ticket(TicketCategory::kVip);
  CHECK(TicketCategory::kVip == vip_ticket.GetCategory());
  CHECK_CLOSE(50.0, vip_ticket.GetPrice(), 1e-6);
  CHECK_EQUAL("VIP ticket for adults.", vip_ticket.GetInfo());
}

TEST(ChildBaseTicketCreation) {
  Ticket child_base_ticket(TicketCategory::kChildBase);
  CHECK(TicketCategory::kChildBase == child_base_ticket.GetCategory());
  CHECK_CLOSE(15.0, child_base_ticket.GetPrice(), 1e-6);
  CHECK_EQUAL("Base ticket for children.", child_base_ticket.GetInfo());
}

TEST(ChildVipTicketCreation) {
  Ticket child_vip_ticket(TicketCategory::kChildVip);
  CHECK(TicketCategory::kChildVip == child_vip_ticket.GetCategory());
  CHECK_CLOSE(30.0, child_vip_ticket.GetPrice(), 1e-6);
  CHECK_EQUAL("VIP ticket for children.", child_vip_ticket.GetInfo());
}

// Transaction tests
TEST_FIXTURE(PaymentFixture, TransactionCannotBeProcessedTwice) {
  auto cash_method = std::make_unique<CashPayment>(context, ticket.GetPrice() + 5.0);
  auto transaction = cashier.CreateTransaction("Test", ticket, std::move(cash_method));

  cashier.ProcessTransaction(*transaction);

  CHECK_THROW(cashier.ProcessTransaction(*transaction), TransactionAlreadyProcessedError);
}

TEST_FIXTURE(PaymentFixture, TransactionWithEmptyVisitorName) {
  auto cash_method = std::make_unique<CashPayment>(context, ticket.GetPrice() + 5.0);
  CHECK_THROW(cashier.CreateTransaction("", ticket, std::move(cash_method)), std::invalid_argument);
}

TEST_FIXTURE(PaymentFixture, AccountTransactionWithEmptyVisitorName) {
  auto card_method = std::make_unique<CardPayment>(context, visitor_account);
  CHECK_THROW(cashier.CreateTransaction("", ticket, std::move(card_method), visitor_account), std::invalid_argument);
}

TEST_FIXTURE(PaymentFixture, TransactionWithNullPaymentMethod) {
  CHECK_THROW(cashier.CreateTransaction("Test", ticket, nullptr), std::invalid_argument);
}

TEST_FIXTURE(PaymentFixture, TransactionWithNullAccountPaymentMethod) {
  CHECK_THROW(cashier.CreateTransaction("Test", ticket, nullptr, visitor_account), std::invalid_argument);
}

TEST_FIXTURE(PaymentFixture, TransactionWithNullVisitorAccount) {
  auto card_method = std::make_unique<CardPayment>(context, visitor_account);
  CHECK_THROW(cashier.CreateTransaction("Test", ticket, std::move(card_method), nullptr), std::invalid_argument);
}

#endif  // PAYMENT_TEST_CC_