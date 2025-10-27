#include "utils/exceptions/not_found_errors.h"

namespace utils {
namespace exceptions {

EmployeeNotFoundError::EmployeeNotFoundError(std::string message)
    : NotFoundError(std::move(message)) {}

MedicalRecordBookNotFoundError::MedicalRecordBookNotFoundError(std::string message)
    : NotFoundError(std::move(message)) {}

TankNotFoundError::TankNotFoundError(std::string message)
    : NotFoundError(std::move(message)) {}

MemberNotFoundError::MemberNotFoundError(std::string message)
    : NotFoundError(std::move(message)) {}

}  // namespace exceptions
}  // namespace utils