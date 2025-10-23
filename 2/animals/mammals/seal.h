#ifndef ANIMALS_MAMMALS_SEAL_H_
#define ANIMALS_MAMMALS_SEAL_H_

#include "animals/mammals/mammal.h"

namespace animals {

class Seal : public SeaMammal {
 public:
  Seal(std::string name, double milk_production, double dive_depth,
       double breath_hold);

  void Eat() const noexcept override;
  std::string GetSpecies() const noexcept override;

  bool CanBalanceBall() const noexcept;
  void LearnToBalanceBall() noexcept;
  void BalanceBall() const noexcept;

 private:
  bool can_balance_ball_;
};

}  // namespace animals

#endif  // ANIMALS_MAMMALS_SEAL_H_