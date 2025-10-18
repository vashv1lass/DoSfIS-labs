#ifndef ANIMALS_ANIMAL_H_
#define ANIMALS_ANIMAL_H_

#include "medical/medical_card.h"

class Animal {
public:
	Animal(const MedicalCard &);

	virtual ~Animal() = default;

	MedicalCard &GetMedicalCard() noexcept;

	virtual std::string GetSpecies() const noexcept = 0;
protected:
	MedicalCard medical_card_;
};

#endif