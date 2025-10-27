#ifndef ALREADY_EXISTS_ERRORS_H_
#define ALREADY_EXISTS_ERRORS_H_

#include "utils/exceptions/base_exceptions.h"

namespace utils {
namespace exceptions {

class MemberAlreadyExistsError : public AlreadyExistsError {
public:
  explicit MemberAlreadyExistsError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // ALREADY_EXISTS_ERRORS_H_