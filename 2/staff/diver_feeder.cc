#include "staff/diver_feeder.h"

namespace staff {

DiverFeeder::DiverFeeder(std::string name, double salary, double oxygen_tank_volume)
    : Employee(std::move(name), salary), oxygen_tank_volume_(oxygen_tank_volume) {
  if (oxygen_tank_volume_ <= 0.0 || oxygen_tank_volume_ > 250.0) {
    throw std::out_of_range("Oxygen tank volume must be positive "
                            "and less or equal to 250 liters.");
  }
}

std::string DiverFeeder::GetRole() const noexcept { return "Diver Feeder"; }

void DiverFeeder::Feed(animals::Animal& animal) {
  std::cout << "Diver " << name_ << " is feeding " << animal.GetName() << ".\n";
  animal.Eat();
}

}  // namespace staff