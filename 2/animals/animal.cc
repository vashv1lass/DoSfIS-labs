#include "animal.h"

Animal::Animal(const MedicalCard &medical_card, const Tank &tank)
	: medical_card_(medical_card), tank_(tank) {}

MedicalCard Animal::GetMedicalCard() const noexcept {
	return this->medical_card_;
}

Tank Animal::GetTank() const noexcept {
	return this->tank_;
}