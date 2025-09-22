#include "basic_tariff.h"

#include <string>
#include <memory>

BasicTariff::BasicTariff() : Tariff(10.0) {}

std::string BasicTariff::GetTariffType() const noexcept {
    return "Basic";
}

std::unique_ptr<Tariff> BasicTariff::Clone() const {
    return std::make_unique<BasicTariff>(*this);
}