#ifndef EMPLOYEES_TRAINER_H_
#define EMPLOYEES_TRAINER_H_

#include <string>
#include <memory>

#include "employee.h"
#include "utils/date.h"
#include "animals/animal.h"

class Trainer : public Employee {
public:
    enum Specialization {
        DOLPHINS,
        SEALS
    };

    Trainer(const std::string &, const Date &, double, const Specialization &);

    Specialization GetSpecialization() const noexcept;

    void TrainAnimal(std::unique_ptr<Animal>) const;
private:
    Specialization specialization_;    
};

#endif // EMPLOYEES_TRAINER_H_