#include "infrastructure/maintenance.h"

#include <cstdlib>

namespace infrastructure {

void MaintenanceUnit::RegisterTank(std::shared_ptr<Tank> tank) {
  if (!tank) {
    throw std::invalid_argument("Tank pointer cannot be null.");
  }
  tanks_[tank->GetID()] = std::move(tank);
}

void MaintenanceUnit::CleanTank(int id) {
  auto it = tanks_.find(id);
  if (it == tanks_.end()) {
    throw utils::exceptions::NotFoundError("Tank not found: " + std::to_string(id));
  }

  auto& tank = it->second;
  if (!tank->IsClean()) {
    PerformCleaning(*tank);
  }
}


void MaintenanceUnit::PerformCleaning(Tank& tank) noexcept {
  tank.MarkClean();
}

}  // namespace infrastructure