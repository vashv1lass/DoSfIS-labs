#include "infrastructure/ecosystem.h"

#include <iostream>

#include "animals/animal.h"

namespace infrastructure {

void Ecosystem::AddAnimal(std::unique_ptr<animals::Animal> animal) {
  if (!animal) {
    throw std::invalid_argument("Animal cannot be null.");
  }
  animals_.push_back(std::move(animal));
}

std::vector<std::string> Ecosystem::GetStatusReport() const {
  std::vector<std::string> report;
  report.reserve(animals_.size());
  for (const auto& a : animals_) {
    report.push_back(a->GetName() + " (" + a->GetSpecies() + ")");
  }
  return report;
}

std::size_t Ecosystem::GetCount() const noexcept { return animals_.size(); }

}  // namespace infrastructure