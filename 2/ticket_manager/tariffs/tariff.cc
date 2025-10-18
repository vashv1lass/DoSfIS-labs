#include "tariff.h"

#include <stdexcept>

Tariff::Tariff(double price) : price_(price) {
    if (price < 0.0) {
        throw std::out_of_range("Negative price value");
    }
}

double Tariff::GetPrice() const noexcept {
    return price_;
}