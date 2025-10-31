#include "staff/trainer.h"

#include "animals/mammals/dolphin.h"
#include "animals/mammals/seal.h"

namespace staff {

Trainer::Trainer(std::string name, double salary)
    : Employee(std::move(name), salary) {}

std::string Trainer::GetRole() const noexcept { return "Trainer"; }

void Trainer::TeachDrawing(animals::Dolphin& dolphin) { 
  dolphin.LearnToDraw();
}

void Trainer::TeachBallBalancing(animals::Seal& seal) {
  seal.LearnToBalanceBall();
}

}  // namespace staff