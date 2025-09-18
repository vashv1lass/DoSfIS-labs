#ifndef TICKET_MANAGER_TARIFFS_BASIC_TARIFF_H_
#define TICKET_MANAGER_TARIFFS_BASIC_TARIFF_H_

#include "tariff.h"

class BasicTariff : public Tariff {
public:
    BasicTariff();

    std::unique_ptr<Tariff> Clone() const override;

    std::string GetTariffType() const override;
};

#endif