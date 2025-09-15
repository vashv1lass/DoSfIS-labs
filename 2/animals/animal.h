#ifndef ANIMALS_ANIMAL_H_
#define ANIMALS_ANIMAL_H_

#include "medical/medical_card.h"
#include "tank/tank.h"

class Animal {
public:
	Animal(const MedicalCard &medical_card, const Tank &tank);
	
	Animal(const Animal &) = default;
	Animal &operator=(const Animal &) = default;
	
	Animal(Animal &&) noexcept = default;
	Animal &operator=(Animal &&) noexcept = default;

	virtual ~Animal() = default;

	void SetMedicalCard(const MedicalCard &);
	void SetTank(const Tank &) noexcept;
	
	MedicalCard GetMedicalCard() const noexcept;
	Tank GetTank() const noexcept;

	virtual std::string GetSpecies() = 0;
protected:
	MedicalCard medical_card_;
	Tank tank_;
};

#endif