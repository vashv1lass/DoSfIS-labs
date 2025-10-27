#ifndef INFRASTRUCTURE_MAINTENANCE_H_
#define INFRASTRUCTURE_MAINTENANCE_H_

#include <string>
#include <memory>
#include <unordered_map>

namespace infrastructure {

class Tank;

}  // namespace infrastructure

namespace infrastructure {

class MaintenanceUnit {
public:
  MaintenanceUnit() = default;

  void RegisterTank(std::shared_ptr<Tank> tank);
  void CleanTank(int id);
private:
  std::unordered_map<int, std::shared_ptr<Tank>> tanks_;

  void PerformCleaning(Tank& tank);
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_MAINTENANCE_H_