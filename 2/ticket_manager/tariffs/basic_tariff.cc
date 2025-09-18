#include "basic_tariff.h"

BasicTariff::BasicTariff() : Tariff(10.0) {}

std::unique_ptr<Tariff> BasicTariff::Clone() const {
    return std::make_unique<BasicTariff>(*this);
}

std::string BasicTariff::GetTariffType() const {
    return "Basic";
}