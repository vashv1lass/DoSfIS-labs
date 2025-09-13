#include "medical_card.h"

MedicalCard::MedicalCard(
    const std::string &name,
    const Date &birth_date,
    const MedicalCard::HealthStatus &health_status
) : name_(name), birth_date_(birth_date), health_status_(health_status) {}

void MedicalCard::SetName(const std::string &name) {
    this->name_ = name;
}

void MedicalCard::SetBirthDate(const Date &birth_date) noexcept {
    this->birth_date_ = birth_date;
}

void MedicalCard::SetHealthStatus(
    const MedicalCard::HealthStatus &health_status
) noexcept {
    this->health_status_ = health_status;
}

std::string MedicalCard::GetName() const noexcept {
    return this->name_;
}

Date MedicalCard::GetBirthDate() const noexcept {
    return this->birth_date_;
}

MedicalCard::HealthStatus MedicalCard::GetHealthStatus() const noexcept {
    return this->health_status_;
}