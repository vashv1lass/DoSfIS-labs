#include "animal.h"

Animal::Animal(const MedicalCard &medical_card, const Tank &tank)
	: medical_card_(medical_card), tank_(tank) {}

void Animal::SetMedicalCard(const MedicalCard &medical_card) {
	this->medical_card_ = medical_card;
}

void Animal::SetTank(const Tank &tank) noexcept {
	this->tank_ = tank;
}

MedicalCard Animal::GetMedicalCard() const noexcept {
	return this->medical_card_;
}

Tank Animal::GetTank() const noexcept {
	return this->tank_;
}