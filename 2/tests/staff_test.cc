#include <UnitTest++/UnitTest++.h>

#include "staff/staff.h"

using namespace staff;

TEST(CashierTest) {
  Cashier cashier("John", 2000.0);
  CHECK_EQUAL("John", cashier.GetName());
  CHECK_CLOSE(2000.0, cashier.GetSalary(), 1e-6);
  CHECK_EQUAL("Cashier", cashier.GetRole());

  CHECK_THROW(Cashier invalid_cashier("", 2000.0), std::invalid_argument);
  CHECK_THROW(Cashier invalid_cashier2("Jane", -1500.0), std::out_of_range);
}

TEST(DiverFeederTest) {
  DiverFeeder diver_feeder("Mike", 2500.0, 60.0);
  CHECK_EQUAL("Mike", diver_feeder.GetName());
  CHECK_CLOSE(60.0, diver_feeder.GetOxygenTankVolume(), 1e-6);
  CHECK_CLOSE(2500.0, diver_feeder.GetSalary(), 1e-6);
  CHECK_EQUAL("Diver Feeder", diver_feeder.GetRole());

  CHECK_THROW(DiverFeeder invalid_diver_feeder("", 2500.0, 60.0), std::invalid_argument);
  CHECK_THROW(DiverFeeder invalid_diver_feeder2("Anna", -2000.0, 60.0), std::out_of_range);
  CHECK_THROW(DiverFeeder invalid_diver_feeder3("Tom", 2500.0, -10.0), std::out_of_range);
}

TEST(TrainerTest) {
  Trainer trainer("Sara", 2200.0);
  CHECK_EQUAL("Sara", trainer.GetName());
  CHECK_CLOSE(2200.0, trainer.GetSalary(), 1e-6);
  CHECK_EQUAL("Trainer", trainer.GetRole());

  CHECK_THROW(Trainer invalid_trainer("", 2200.0), std::invalid_argument);
  CHECK_THROW(Trainer invalid_trainer2("Bob", -1800.0), std::out_of_range);
}

TEST(VeterinarianTest) {
  Veterinarian vet("Dr. Alice", 3000.0);
  CHECK_EQUAL("Dr. Alice", vet.GetName());
  CHECK_CLOSE(3000.0, vet.GetSalary(), 1e-6);
  CHECK_EQUAL("Veterinarian", vet.GetRole());

  CHECK_THROW(Veterinarian invalid_vet("", 3000.0), std::invalid_argument);
  CHECK_THROW(Veterinarian invalid_vet2("Dr. Eve", -2500.0), std::out_of_range);
}