#include "tariff.h"

Tariff::Tariff(double price) : price_(price) {}

double Tariff::GetPrice() const noexcept {
    return this->price_;
}