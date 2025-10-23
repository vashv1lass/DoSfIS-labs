#ifndef ANIMALS_REPTILE_SEA_TURTLE_H_
#define ANIMALS_REPTILE_SEA_TURTLE_H_

#include "animals/reptile/reptile.h"

namespace animals {

class SeaTurtle : public Reptile {
 public:
  SeaTurtle(std::string name, double body_temperature,
            double shell_diameter);
  void Move() const noexcept override;
  std::string GetSpecies() const noexcept override;

  double GetShellDiameter() const noexcept;

 private:
  double shell_diameter_;
};

}  // namespace animals

#endif  // ANIMALS_REPTILE_SEA_TURTLE_H_