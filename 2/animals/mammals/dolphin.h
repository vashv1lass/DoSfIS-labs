#ifndef ANIMALS_MAMMALS_DOLPHIN_H_
#define ANIMALS_MAMMALS_DOLPHIN_H_

#include "animals/mammals/mammal.h"

namespace animals {

class Dolphin : public SeaMammal {
 public:
  Dolphin(std::string name, double milk_production, double dive_depth,
          double breath_hold, int iq);

  void Eat() const noexcept override;
  std::string GetSpecies() const noexcept override;

  bool CanDraw() const noexcept;
  void LearnToDraw() noexcept;
  void Draw() const noexcept;

 private:
  int iq_;
  bool can_draw_;
};

}  // namespace animals

#endif  // ANIMALS_MAMMALS_DOLPHIN_H_