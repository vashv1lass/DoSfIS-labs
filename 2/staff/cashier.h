#ifndef STAFF_CASHIER_H_
#define STAFF_CASHIER_H_

#include <string>

#include "staff/employee.h"
#include "payment/transaction.h"

namespace staff {

class Cashier : public Employee {
 public:
  Cashier(std::string name, double salary);
  std::string GetRole() const noexcept override;
  void ProcessTransaction(payment::Transaction& transaction);
};

}  // namespace staff

#endif  // CASHIER_H_