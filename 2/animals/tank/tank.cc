#include "tank.h"

Tank::Tank(int id, double volume) : id_(id), volume_(volume) {}

void Tank::SetId(int id) noexcept {
	this->id_ = id;
}

void Tank::SetVolume(double volume) noexcept {
	this->volume_ = volume;
}

int Tank::GetId() const noexcept {
	return this->id_;
}

double Tank::GetVolume() const noexcept {
	return this->volume_;
}
