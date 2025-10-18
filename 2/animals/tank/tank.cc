#include "tank.h"

#include "utils/id_generator.h"

#include <vector>

Tank::Tank(double volume, double water_salinity)
	: id_(IDGenerator::GenerateID()), volume_(volume), water_salinity_(water_salinity) {}

void Tank::SetWaterSalinity(double water_salinity) noexcept {
	water_salinity_ = water_salinity;
}

int Tank::GetId() const noexcept {
	return id_;
}

double Tank::GetDepth() const noexcept {
	return depth_;
}

double Tank::GetVolume() const noexcept {
	return volume_;
}

double Tank::GetWaterSalinity() const noexcept {
	return water_salinity_;
}