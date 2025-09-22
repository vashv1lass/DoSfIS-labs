#include "vip_tariff.h"

VIPTariff::VIPTariff() : Tariff(40.0) {}

std::string VIPTariff::GetTariffType() const noexcept {
    return "VIP";
}

std::unique_ptr<Tariff> VIPTariff::Clone() const {
    return std::make_unique<VIPTariff>(*this);
}