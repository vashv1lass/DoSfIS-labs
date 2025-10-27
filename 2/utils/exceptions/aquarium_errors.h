#ifndef AQUARIUM_ERRORS_H_
#define AQUARIUM_ERRORS_H_

#include "utils/exceptions/base_exceptions.h"

namespace utils {
namespace exceptions {

class ClosedAquariumError : public BaseException {
public:
  explicit ClosedAquariumError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // AQUARIUM_ERRORS_H_