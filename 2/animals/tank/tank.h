#ifndef ANIMALS_TANK_TANK_H_
#define ANIMALS_TANK_TANK_H_

class Tank {
public:
	Tank(double, double);
	
	Tank(const Tank &) = default;
	Tank &operator=(const Tank &) = default;
	
	Tank(Tank &&) noexcept = default;
	Tank &operator=(Tank &&) noexcept = default;
	
	void SetWaterSalinity(double) noexcept;

	int GetId() const noexcept;
	double GetDepth() const noexcept;
	double GetVolume() const noexcept;
	double GetWaterSalinity() const noexcept;
private:
	int id_;

	double depth_;
	double volume_;

	double water_salinity_;
};

#endif // ANIMALS_TANK_TANK_H_