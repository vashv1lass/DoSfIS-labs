#ifndef ANIMALS_TANK_TANK_H_
#define ANIMALS_TANK_TANK_H_

class Tank {
public:
	Tank(int id = 0, double volume = -1.f);
	
	Tank(const Tank &) = default;
	Tank &operator=(const Tank &) = default;
	
	Tank(Tank &&) noexcept = default;
	Tank &operator=(Tank &&) noexcept = default;
	
	void SetId(int) noexcept;
	void SetVolume(double) noexcept;
	
	int GetId() const noexcept;
	double GetVolume() const noexcept;
private:
	int id_;
	double volume_;
};

#endif // ANIMALS_TANK_TANK_H_