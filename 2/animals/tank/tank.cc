#include "tank.h"

#include "utils/id_generator.h"

#include <vector>

Tank::Tank(double volume, double water_salinity)
	: id_(IDGenerator::GenerateID()),
	volume_(volume), water_salinity_(water_salinity) {}

void Tank::SetWaterSalinity(double water_salinity) noexcept {
	this->water_salinity_ = water_salinity;
}

int Tank::GetId() const noexcept {
	return this->id_;
}

double Tank::GetDepth() const noexcept {
	return this->depth_;
}

double Tank::GetVolume() const noexcept {
	return this->volume_;
}

double Tank::GetWaterSalinity() const noexcept {
	return this->water_salinity_;
}