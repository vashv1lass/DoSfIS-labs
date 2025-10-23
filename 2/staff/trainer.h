#ifndef STAFF_TRAINER_H_
#define STAFF_TRAINER_H_

#include "staff/employee.h"
#include "animals/mammals/dolphin.h"
#include "animals/mammals/seal.h"

#include <iostream>

namespace staff {

class Trainer : public Employee {
 public:
  Trainer(std::string name, double salary, int experience_level);
  std::string GetRole() const noexcept override;

  void TeachDrawing(animals::Dolphin& dolphin);
  void TeachBallBalancing(animals::Seal& seal);

 private:
  int experience_level_;
};

}  // namespace staff

#endif  // STAFF_TRAINER_H_