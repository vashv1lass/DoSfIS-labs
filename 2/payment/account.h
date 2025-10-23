#ifndef PAYMENT_ACCOUNT_H_
#define PAYMENT_ACCOUNT_H_

#include <string>

namespace payment {

class Account {
 public:
  explicit Account(std::string owner, double balance);

  const std::string& GetOwner() const noexcept;
  double GetBalance() const noexcept;

  void Deposit(double amount);
  void Withdraw(double amount);
  bool HasEnough(double amount) const noexcept;

 private:
  std::string owner_;
  double balance_;
};

}  // namespace payment

#endif  // PAYMENT_ACCOUNT_H_