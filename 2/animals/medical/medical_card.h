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

    MedicalCard(const std::string &, const Date &, double, const HealthStatus &);

    std::string GetName() const noexcept;

    Date GetBirthDate() const noexcept;

    void SetWeight(double) noexcept;
    double GetWeight() const noexcept;
    
    void SetHealthStatus(const HealthStatus &) noexcept;
    HealthStatus GetHealthStatus() const noexcept;
private:
    std::string name_;
    Date birth_date_;

    double weight_;

    HealthStatus health_status_;
};

#endif // ANIMALS_MEDICAL_MEDICAL_CARD_H_