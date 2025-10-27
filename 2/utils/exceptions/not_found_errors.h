#ifndef NOT_FOUND_ERRORS_H_
#define NOT_FOUND_ERRORS_H_

#include "utils/exceptions/base_exceptions.h"

namespace utils {
namespace exceptions {

class EmployeeNotFoundError : public NotFoundError {
public:
  explicit EmployeeNotFoundError(std::string message);
};

class MedicalRecordBookNotFoundError : public NotFoundError {
public:
  explicit MedicalRecordBookNotFoundError(std::string message);
};

class TankNotFoundError : public NotFoundError {
public:
  explicit TankNotFoundError(std::string message);
};

class MemberNotFoundError : public NotFoundError {
public:
  explicit MemberNotFoundError(std::string message);
};

}  // namespace exceptions
}  // namespace utils

#endif  // NOT_FOUND_ERRORS_H_