#include "feeder.h"

#include <string>
#include <map>
#include <iostream>
#include <memory>

Feeder::Feeder(const std::string &name, const Date &hire_date, double salary)
    : Employee(name, hire_date, salary) {}

void Feeder::AddFeeding(const Date &date, std::shared_ptr<Animal> animal) {
    feed_schedule_[date] = animal;
}

void Feeder::FeedAnimals(const Date &today) {
    auto it = feed_schedule_.find(today);
    if (it != feed_schedule_.end()) {
        if (auto animal_ptr = it->second.lock()) {
            std::cout << "Feeding an animal " << animal_ptr->GetMedicalCard().GetName()
                      << ", species: " << animal_ptr->GetSpecies() << " on " 
                      << today.GetDay() << "." << today.GetMonth() << "." << today.GetYear() << std::endl;
        }
    }
}