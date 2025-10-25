#ifndef ANIMALS_FISH_STINGRAY_H_
#define ANIMALS_FISH_STINGRAY_H_

#include "animals/fish/fish.h"

namespace animals {

class Stingray : public Fish {
public:
  Stingray(std::string name, double swim_speed, bool venomous,
           double fin_span);
  void Move() const noexcept override;
  std::string GetSpecies() const noexcept override;

  bool IsVenomous() const noexcept;

  void SetFinSpan(double fin_span);
  double GetFinSpan() const;

private:
  bool venomous_;
  double fin_span_;
};

}  // namespace animals

#endif  // ANIMALS_FISH_STINGRAY_H_