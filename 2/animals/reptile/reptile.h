#ifndef ANIMALS_REPTILE_REPTILE_H_
#define ANIMALS_REPTILE_REPTILE_H_

#include "animals/animal.h"

namespace animals {

class Reptile : public Animal {
 public:
  Reptile(std::string name, double body_temperature);
  void Move() const noexcept override;
  void Eat() const noexcept override;
  std::string GetSpecies() const noexcept override;

  void SetBodyTemperature(double temperature);
  double GetBodyTemperature() const noexcept;

 protected:
  double body_temperature_;
};

}  // namespace animals

#endif  // ANIMALS_REPTILE_REPTILE_H_