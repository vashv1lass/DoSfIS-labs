#ifndef TICKET_MANAGER_TARIFFS_BASIC_TARIFF_H_
#define TICKET_MANAGER_TARIFFS_BASIC_TARIFF_H_

#include <string>
#include <memory>

#include "tariff.h"

class BasicTariff : public Tariff {
public:
    BasicTariff();

    std::string GetTariffType() const noexcept override;

    std::unique_ptr<Tariff> Clone() const override;
};

#endif // TICKET_MANAGER_TARIFFS_BASIC_TARIFF_H_