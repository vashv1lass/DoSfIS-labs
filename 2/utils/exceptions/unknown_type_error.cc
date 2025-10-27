#include "utils/exceptions/unknown_type_error.h"

namespace utils {
namespace exceptions {

UnknownDiagnosisTypeError::UnknownDiagnosisTypeError(std::string message)
    : UnknownTypeError(std::move(message)) {}

UnknownTicketTypeError::UnknownTicketTypeError(std::string message)
    : UnknownTypeError(std::move(message)) {}
  
}  // namespace exceptions
}  // namespace utils