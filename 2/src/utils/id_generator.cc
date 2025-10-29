#include "utils/id_generator.h"

namespace utils {

IDGenerator& IDGenerator::Instance() noexcept {
  static IDGenerator instance;
  return instance;
}

int IDGenerator::NextID() noexcept {
  return ++counter_;
}

}  // namespace utils