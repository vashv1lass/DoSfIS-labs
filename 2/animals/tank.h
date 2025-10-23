#ifndef ANIMALS_TANK_H_
#define ANIMALS_TANK_H_

#include <memory>
#include <stdexcept>
#include <vector>

#include "animals/animal.h"

namespace animals {

class Tank {
 public:
  Tank(double depth, double volume);
  void AddAnimal(std::shared_ptr<Animal> animal);
  void ShowAll() const noexcept;

  double GetDepth() const noexcept;
  double GetVolume() const noexcept;
  void SetDepth(double depth);
  void SetVolume(double volume);

 private:
  double depth_;
  double volume_;
  std::vector<std::shared_ptr<Animal>> animals_;
};

}  // namespace animals

#endif  // ANIMALS_TANK_H_