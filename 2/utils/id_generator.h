#ifndef UTILS_ID_GENERATOR_H_
#define UTILS_ID_GENERATOR_H_

#include <atomic>

namespace utils {

class IDGenerator {
public:
  static IDGenerator& Instance() noexcept;

  int NextID() noexcept;

private:
  IDGenerator() = default;
  ~IDGenerator() = default;

  IDGenerator(const IDGenerator&) = delete;
  IDGenerator& operator=(const IDGenerator&) = delete;

  std::atomic<int> counter_{0};
};

}  // namespace utils

#endif  // UTILS_ID_GENERATOR_H_
