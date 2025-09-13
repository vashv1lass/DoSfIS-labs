#ifndef ANIMALS_MEDICAL_MEDICAL_CARD_H_
#define ANIMALS_MEDICAL_MEDICAL_CARD_H_

#include <string>

#include "utils/date.h"

class MedicalCard {
public:
    enum HealthStatus {
        HEALTHY,
        SICK,
        INJURED
    };

    MedicalCard(const std::string &, const Date &, const HealthStatus &);

    MedicalCard(const MedicalCard &) = default;
    MedicalCard &operator=(const MedicalCard &) = default;

    MedicalCard(MedicalCard &&) = default;
    MedicalCard &operator=(MedicalCard &&) = default;

    ~MedicalCard() = default;

    void SetName(const std::string &);
    void SetBirthDate(const Date &) noexcept;
    void SetHealthStatus(const HealthStatus &) noexcept;

    std::string GetName() const noexcept;
    Date GetBirthDate() const noexcept;
    HealthStatus GetHealthStatus() const noexcept;
private:
    std::string name_;
    Date birth_date_;
    HealthStatus health_status_;
};

#endif // ANIMALS_MEDICAL_MEDICAL_CARD_H_