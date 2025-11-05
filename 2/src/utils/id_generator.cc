#include "utils/id_generator.h"

namespace utils {

IDGenerator& IDGenerator::Instance() noexcept {
  static IDGenerator instance;
  return instance;
}

int IDGenerator::NextID() noexcept {
  return ++counter_;
}

#ifdef UNIT_TEST

void IDGenerator::Reset() noexcept {
  counter_ = 0;
}

#endif

}  // namespace utils