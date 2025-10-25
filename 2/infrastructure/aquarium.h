#ifndef INFRASTRUCTURE_AQUARIUM_H_
#define INFRASTRUCTURE_AQUARIUM_H_

#include <memory>
#include <mutex>
#include <string>

#include "infrastructure/ecosystem.h"
#include "infrastructure/human_resources.h"
#include "infrastructure/medical_department.h"
#include "infrastructure/membership.h"
#include "infrastructure/maintenance.h"
#include "infrastructure/schedule.h"
#include "payment/context.h"

namespace infrastructure {

class Aquarium {
public:
  static Aquarium& Instance();

  Aquarium(const Aquarium&) = delete;
  Aquarium& operator=(const Aquarium&) = delete;
  Aquarium(Aquarium&&) = delete;
  Aquarium& operator=(Aquarium&&) = delete;

  void Open() noexcept;
  void Close() noexcept;

  Ecosystem& GetEcosystem();
  HumanResources& GetHumanResources();
  MembershipSystem& GetMembershipSystem();
  MaintenanceUnit& GetMaintenanceUnit();
  Schedule& GetSchedule();
  payment::PaymentContext& GetPaymentContext();

private:
  Aquarium();
  ~Aquarium() = default;

  Ecosystem ecosystem_;
  HumanResources human_resources_;
  MedicalDepartment medical_department_;
  MembershipSystem membership_system_;
  MaintenanceUnit maintenance_unit_;
  Schedule schedule_;
  payment::PaymentContext payment_context_;

  bool is_opened_;
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_AQUARIUM_H_