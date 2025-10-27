#ifndef STAFF_DIVER_FEEDER_H_
#define STAFF_DIVER_FEEDER_H_

#include <iostream>
#include <string>

#include "staff/employee.h"

namespace animals {

class Animal;

}  // namespace animals

namespace staff {

class DiverFeeder : public Employee {
public:
  DiverFeeder(std::string name, double salary, double oxygen_tank_volume);
  std::string GetRole() const noexcept override;
  
  void Feed(animals::Animal& animal);

private:
  double oxygen_tank_volume_;
};

}  // namespace staff

#endif  // OCEANARIUM_STAFF_DIVER_FEEDER_H_