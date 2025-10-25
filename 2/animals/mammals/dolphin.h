#ifndef ANIMALS_MAMMALS_DOLPHIN_H_
#define ANIMALS_MAMMALS_DOLPHIN_H_

#include "animals/mammals/mammal.h"
#include "staff/trainer.h"

namespace animals {

class Dolphin : public SeaMammal {
public:
  Dolphin(std::string name, double milk_production, double dive_depth,
          double breath_hold, int iq);

  std::string GetSpecies() const noexcept override;

  bool CanDraw() const noexcept;
  void Draw() const noexcept;

protected:
  void Eat() const noexcept override;

  void LearnToDraw() noexcept;
  
private:
  int iq_;
  bool can_draw_;

  friend class staff::Trainer;
};

}  // namespace animals

#endif  // ANIMALS_MAMMALS_DOLPHIN_H_