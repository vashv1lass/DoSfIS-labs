#ifndef ANIMALS_MAMMALS_MAMMAL_H_
#define ANIMALS_MAMMALS_MAMMAL_H_

#include "animals/animal.h"

namespace animals {

class Mammal : public Animal {
public:
  Mammal(std::string name, double milk_production);
  void Move() const noexcept override;
  std::string GetSpecies() const noexcept override;

  void SetMilkProduction(double milk_production);
  double GetMilkProduction() const noexcept;

protected:
  double milk_production_;

  void Eat() const noexcept override;
};

class SeaMammal : public Mammal {
public:
  SeaMammal(std::string name, double milk_production, double dive_depth,
            double breath_hold);
  void Move() const noexcept override;
  std::string GetSpecies() const noexcept override;

  double GetDiveDepth() const noexcept;
  double GetBreathHoldTime() const noexcept;

protected:
  double dive_depth_;
  double breath_hold_time_;
};

}  // namespace animals

#endif  // ANIMALS_MAMMALS_MAMMAL_H_