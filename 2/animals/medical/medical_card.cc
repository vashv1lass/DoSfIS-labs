#include "medical_card.h"

#include "utils/date.h"

MedicalCard::MedicalCard(
    const std::string &name,
    const Date &birth_date,
    double weight,
    const MedicalCard::HealthStatus &health_status
) : name_(name), birth_date_(birth_date), weight_(weight),
    health_status_(health_status) {}

void MedicalCard::SetHealthStatus(
    const MedicalCard::HealthStatus &health_status
) noexcept {
    this->health_status_ = health_status;
}

void MedicalCard::SetWeight(double weight) {
    this->weight_ = weight;
}

std::string MedicalCard::GetName() const noexcept {
    return this->name_;
}

Date MedicalCard::GetBirthDate() const noexcept {
    return this->birth_date_;
}

double MedicalCard::GetWeight() const noexcept {
    return this->weight_;
}

MedicalCard::HealthStatus MedicalCard::GetHealthStatus() const noexcept {
    return this->health_status_;
}