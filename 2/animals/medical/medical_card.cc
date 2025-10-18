#include "medical_card.h"

#include <string>
#include <stdexcept>

#include "utils/date.h"

MedicalCard::MedicalCard(
    const std::string &name, const Date &birth_date, double weight,
    const MedicalCard::HealthStatus &health_status
) : name_(name), birth_date_(birth_date), weight_(weight), health_status_(health_status) {}

std::string MedicalCard::GetName() const noexcept {
    return name_;
}

Date MedicalCard::GetBirthDate() const noexcept {
    return birth_date_;
}

void MedicalCard::SetWeight(double weight) {
    if (weight < 0 || weight > 2000) {
        throw std::out_of_range("Weight must be between 0 and 2000 kg.");
    }
    weight_ = weight;
}

double MedicalCard::GetWeight() const noexcept {
    return weight_;
}

void MedicalCard::SetHealthStatus(const MedicalCard::HealthStatus &health_status) noexcept {
    health_status_ = health_status;
}

MedicalCard::HealthStatus MedicalCard::GetHealthStatus() const noexcept {
    return health_status_;
}