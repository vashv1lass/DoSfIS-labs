#include "utils/exceptions/already_exists_errors.h"

namespace utils {
namespace exceptions {

MemberAlreadyExistsError::MemberAlreadyExistsError(std::string message)
    : AlreadyExistsError(std::move(message)) {}

}  // namespace exceptions
}  // namespace utils