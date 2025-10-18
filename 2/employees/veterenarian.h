#ifndef EMPLOYEES_VETERENARIAN_H_
#define EMPLOYEES_VETERENARIAN_H_

#include <string>
#include <memory>

#include "employee.h"
#include "utils/date.h"
#include "animals/animal.h"

class Veterenarian : public Employee {
public:
    enum Specialization {
        FISH,
        MAMMALS,
        REPTILES
    };

    Veterenarian(const std::string &, const Date &, double, const Specialization &, const std::string &);

    Specialization GetSpecialization() const noexcept;

    std::string GetLicenseNumber() const noexcept;    

    void TreatAnimal(std::unique_ptr<Animal>) const;
private:
    Specialization specialization_;
    std::string license_number_;
};

#endif // EMPLOYEES_VETERENARIAN_H_