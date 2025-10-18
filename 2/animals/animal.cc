#include "animal.h"

#include "medical/medical_card.h"

Animal::Animal(const MedicalCard &medical_card)
	: medical_card_(medical_card) {}

MedicalCard &Animal::GetMedicalCard() noexcept {
	return medical_card_;
}