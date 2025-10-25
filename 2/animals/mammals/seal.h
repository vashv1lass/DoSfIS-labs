#ifndef ANIMALS_MAMMALS_SEAL_H_
#define ANIMALS_MAMMALS_SEAL_H_

#include "animals/mammals/mammal.h"
#include "staff/trainer.h"

namespace animals {

class Seal : public SeaMammal {
public:
  Seal(std::string name, double milk_production, double dive_depth,
       double breath_hold);

  std::string GetSpecies() const noexcept override;

  bool CanBalanceBall() const noexcept;
  void BalanceBall() const noexcept;

protected:
  void Eat() const noexcept override;

  void LearnToBalanceBall() noexcept;
  
private:
  bool can_balance_ball_;

  friend class staff::Trainer;
};

}  // namespace animals

#endif  // ANIMALS_MAMMALS_SEAL_H_