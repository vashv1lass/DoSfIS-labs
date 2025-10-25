#ifndef ANIMALS_FISH_SHARK_H_
#define ANIMALS_FISH_SHARK_H_

#include "animals/fish/fish.h"

namespace animals {

class Shark : public Fish {
public:
  std::string GetSpecies() const noexcept override;

protected:
  void Eat() const noexcept override;
};

}  // namespace animals

#endif  // ANIMALS_FISH_SHARK_H_