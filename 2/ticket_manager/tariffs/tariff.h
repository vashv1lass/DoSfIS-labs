#ifndef TICKET_MANAGER_TARIFFS_TARIFF_H_
#define TICKET_MANAGER_TARIFFS_TARIFF_H_

#include <string>

class Tariff {
public:
    Tariff(double);

    virtual ~Tariff() = default;

    virtual std::unique_ptr<Tariff> Clone() const = 0;

    virtual double GetPrice() const noexcept;
    virtual std::string GetTariffType() const = 0;
protected:
    double price_;
};

#endif // TICKET_MANAGER_TARIFFS_TARIFF_H_