#include "staff/trainer.h"

#include "animals/mammals/dolphin.h"
#include "animals/mammals/seal.h"

namespace staff {

Trainer::Trainer(std::string name, double salary, int experience_level)
    : Employee(std::move(name), salary), experience_level_(experience_level) {
  if (experience_level_ <= 0) {
    throw std::invalid_argument("Experience level must be positive.");
  }
}

std::string Trainer::GetRole() const noexcept { return "Trainer"; }

void Trainer::TeachDrawing(animals::Dolphin& dolphin) { 
  std::cout << "Trainer " << name_ << " is teaching " << dolphin.GetName()
            << " to draw.\n";
  dolphin.LearnToDraw();
}

void Trainer::TeachBallBalancing(animals::Seal& seal) {
  std::cout << "Trainer " << name_ << " is teaching " << seal.GetName()
            << " to balance a ball.\n";
  seal.LearnToBalanceBall();
}

}  // namespace staff