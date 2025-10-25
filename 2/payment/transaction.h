#ifndef PAYMENT_TRANSACTION_H_
#define PAYMENT_TRANSACTION_H_

#include <memory>
#include <string>

#include "payment/ticket.h"
#include "payment/payment_methods/payment_method_interfaces.h"
#include "payment/account.h"

namespace payment {

class Transaction {
public:
  Transaction(std::string visitor_name,
              Ticket ticket,
              std::unique_ptr<payment_methods::IPaymentMethod> method,
              std::shared_ptr<Account> visitor_account = nullptr);

  void Process();
  double GetTotalAmount() const noexcept;

private:
  std::string visitor_name_;
  Ticket ticket_;
  std::unique_ptr<payment_methods::IPaymentMethod> method_;
  std::shared_ptr<Account> visitor_account_;
  bool is_paid_;
};

}  // namespace payment

#endif  // PAYMENT_TRANSACTION_H_