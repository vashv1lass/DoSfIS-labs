#ifndef ANIMALS_ANIMAL_H_
#define ANIMALS_ANIMAL_H_

#include "medical/medical_card.h"
#include "tank/tank.h"

class Animal {
public:
	Animal(const MedicalCard &medical_card, const Tank &tank);

	virtual ~Animal() = default;

	MedicalCard GetMedicalCard() const noexcept;
	Tank GetTank() const noexcept;

	virtual std::string GetSpecies() const noexcept = 0;
protected:
	MedicalCard medical_card_;
	Tank tank_;
};

#endif