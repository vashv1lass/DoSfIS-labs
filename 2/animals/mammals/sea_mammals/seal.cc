#include "seal.h"

#include <string>
#include <stdexcept>
#include <iostream>

#include "medical/medical_card.h"
#include "tank/tank.h"
#include "animal.h"
#include "sea_mammal.h"

Seal::Seal(const MedicalCard &medical_card,
           const Tank &tank, double milk_production,
           double swim_speed) 
    : Animal(medical_card), SeaMammal(medical_card, tank, milk_production),
      swim_speed_(swim_speed), can_balance_ball_(false) {}

void Seal::SetMilkProduction(double milk_production) {
    if (milk_production < 0 || milk_production > 35) {
        throw std::out_of_range("Seal milk production must be between 0 and"
                                " 35 liters per day.");
    }
    milk_production_ = milk_production;
}

void Seal::SetSwimSpeed(double swim_speed) {
    if (swim_speed < 0 || swim_speed > 50) {
        throw std::out_of_range("Seal swim speed must be between 0 and "
                                "50 km/h.");
    }
    swim_speed_ = swim_speed;
}

double Seal::GetSwimSpeed() const noexcept {
    return swim_speed_;
}

void Seal::TrainToBalanceBall() noexcept {
    can_balance_ball_ = true;
}

bool Seal::CanBalanceBall() const noexcept {
    return can_balance_ball_;
}

std::string Seal::GetSpecies() const noexcept {
    return "Seal";
}

void Seal::BalanceBall() const {
    if (can_balance_ball_) {
        std::cout << "The seal is balancing the ball!" << std::endl;
    } else {
        // throw CannotPerformTrickException("This seal cannot balance a ball.");
    }
}