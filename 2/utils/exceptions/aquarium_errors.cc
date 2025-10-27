#include "utils/exceptions/aquarium_errors.h"

namespace utils {
namespace exceptions {

ClosedAquariumError::ClosedAquariumError(std::string message)
    : BaseException(std::move(message)) {}

}  // namespace exceptions
}  // namespace utils