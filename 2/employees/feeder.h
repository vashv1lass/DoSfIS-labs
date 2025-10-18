#ifndef EMPLOYEES_FEEDER_H_
#define EMPLOYEES_FEEDER_H_

#include <string>
#include <map>
#include <memory>

#include "employee.h"
#include "utils/date.h"
#include "animals/animal.h"

class Feeder : public Employee {
public:
    Feeder(const std::string &, const Date &, double);

    void AddFeeding(const Date &, std::shared_ptr<Animal>);
    void FeedAnimals(const Date &);
private:
    std::map<Date, std::weak_ptr<Animal>> feed_schedule_;
};

#endif // EMPLOYEES_FEEDER_H_