#include "vip_tariff.h"

VIPTariff::VIPTariff() : Tariff(40) {}

std::unique_ptr<Tariff> VIPTariff::Clone() const {
    return std::make_unique<VIPTariff>(*this);
}

std::string VIPTariff::GetTariffType() const {
    return "VIP";
}