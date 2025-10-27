#ifndef UNKNOWN_TYPE_ERROR_H_
#define UNKNOWN_TYPE_ERROR_H_

#include "utils/exceptions/base_exceptions.h"

namespace utils {
namespace exceptions {

class UnknownDiagnosisTypeError : public UnknownTypeError {
public:
  explicit UnknownDiagnosisTypeError(std::string message);
};

class UnknownTicketTypeError : public UnknownTypeError {
public:
  explicit UnknownTicketTypeError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // UNKNOWN_TYPE_ERROR_H_