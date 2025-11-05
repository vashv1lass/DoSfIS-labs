#include "infrastructure/tank.h"

#include "animals/animal.h"
#include "utils/id_generator.h"

namespace infrastructure {

Tank::Tank(double depth, double volume)
    : id_(utils::IDGenerator::Instance().NextID()),
      depth_(depth),
      volume_(volume),
      is_clean_(true) {
  if (depth_ <= 0.0 || depth_ > 100.0) {
    throw std::out_of_range("Tank depth must be positive and "
                            "less or equal to 100 meters.");
  }
  if (volume_ <= 0.0 || volume_ > 100000.0) {
    throw std::out_of_range("Tank volume must be positive and "
                            "less or equal to 100000 m³.");
  }
}

void Tank::AddAnimal(std::shared_ptr<animals::Animal> animal) {
  if (!animal) {
    throw std::invalid_argument("Cannot add null animal to tank.");
  }
  animals_.push_back(std::move(animal));
}

int Tank::GetID() const noexcept { return id_; }

double Tank::GetDepth() const noexcept { return depth_; }

double Tank::GetVolume() const noexcept { return volume_; }

const std::vector<std::shared_ptr<animals::Animal>>& Tank::GetAnimals() const noexcept {
  return animals_;
}

bool Tank::IsClean() const noexcept { return is_clean_; }

void Tank::SetDepth(double depth) {
  if (depth <= 0.0 || depth > 100.0) {
    throw std::out_of_range("Tank depth must be positive and "
                            "less or equal to 100 meters.");
  }
  depth_ = depth;
}

void Tank::SetVolume(double volume) {
  if (volume <= 0.0 || volume > 100000.0) {
    throw std::out_of_range("Tank volume must be positive and "
                            "less or equal to 100000 m³.");
  }
  volume_ = volume;
}

void Tank::MarkClean() noexcept {
  is_clean_ = true;
}

void Tank::MarkDirty() noexcept {
  is_clean_ = false;
}

}  // namespace infrastructure