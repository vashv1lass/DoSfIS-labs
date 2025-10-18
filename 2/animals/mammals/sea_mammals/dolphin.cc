#include "dolphin.h"

#include <string>
#include <stdexcept>
#include <iostream>

#include "medical/medical_card.h"
#include "tank/tank.h"
#include "animal.h"
#include "sea_mammal.h"

Dolphin::Dolphin(const MedicalCard &medical_card, const Tank &tank,
                 double milk_production, int iq)
    : Animal(medical_card), SeaMammal(medical_card, tank, milk_production), iq_(iq), can_draw_(false) {}

void Dolphin::SetMilkProduction(double milk_production) {
    if (milk_production < 0 || milk_production > 50) {
        throw std::out_of_range("Dolphin milk production must be between 0 and"
                                " 50 liters per day.");
    }
    milk_production_ = milk_production;
}

int Dolphin::GetIQ() const noexcept {
    return iq_;
}

void Dolphin::TrainToDraw() noexcept {
    can_draw_ = true;
}

bool Dolphin::CanDraw() const noexcept {
    return can_draw_;
}

std::string Dolphin::GetSpecies() const noexcept {
    return "Dolphin";
}

void Dolphin::Draw() const {
    if (can_draw_) {
        std::cout << "  __     __\n"
                     "o'')}____//\n"
                     " `_/      )\n"
                     " (_(_/-(_/\\\n";
    } else {
        // throw CannotPerformTrickException("This dolphin cannot draw.");
    }
}