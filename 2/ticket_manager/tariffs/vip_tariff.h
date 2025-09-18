#ifndef TICKET_MANAGER_TARIFFS_VIP_TARIFF_H_
#define TICKET_MANAGER_TARIFFS_VIP_TARIFF_H_

#include "tariff.h"

class VIPTariff : public Tariff {
public:
    VIPTariff();

    std::unique_ptr<Tariff> Clone() const override;
    
    std::string GetTariffType() const override;
};

#endif