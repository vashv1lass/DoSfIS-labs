#include "animals/animal.h"

#include <string>
#include <stdexcept>
#include <memory>

namespace animals {

Animal::Animal(std::string name)
    : name_(std::move(name)) {
  if (name_.empty()) {
    throw std::invalid_argument("Animal name cannot be empty.");
  }
}

const std::string& Animal::GetName() const noexcept {
  return name_;
}

}  // namespace animals