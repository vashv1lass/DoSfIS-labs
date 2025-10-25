#ifndef ANIMALS_FISH_FISH_H_
#define ANIMALS_FISH_FISH_H_

#include "animals/animal.h"

namespace animals {

class Fish : public Animal {
public:
  Fish(std::string name, double swim_speed);
  void Move() const noexcept override;
  std::string GetSpecies() const noexcept override;

  double GetSwimSpeed() const noexcept;
  void SetSwimSpeed(double speed);

protected:
  double swim_speed_;

  void Eat() const noexcept override;
};

}  // namespace animals

#endif  // ANIMALS_FISH_FISH_H_