#include "infrastructure/aquarium.h"

#include <iostream>
#include <chrono>
#include <iomanip>

#include "utils/exceptions/aquarium_errors.h"

namespace infrastructure {

Aquarium& Aquarium::Instance() {
  static Aquarium instance;
  return instance;
}

Aquarium::Aquarium()
    : ecosystem_(),
    human_resources_(),
    maintenance_unit_(),
    medical_department_(),
    membership_system_(),
    schedule_(),
    payment_context_(std::make_shared<payment::Account>(payment::Account("Aquarium", 0.0))),
    is_opened_(false) {}

void Aquarium::Open() {
  is_opened_ = true;
}

void Aquarium::Close() {
  is_opened_ = false;
}

Ecosystem& Aquarium::GetEcosystem() {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return ecosystem_; 
}

const Ecosystem& Aquarium::GetEcosystem() const {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return ecosystem_; 
}

HumanResources& Aquarium::GetHumanResources() {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return human_resources_;
}

const HumanResources& Aquarium::GetHumanResources() const {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return human_resources_;
}

MembershipSystem& Aquarium::GetMembershipSystem() {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return membership_system_;
}

const MembershipSystem& Aquarium::GetMembershipSystem() const {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return membership_system_;
}

MaintenanceUnit& Aquarium::GetMaintenanceUnit() {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return maintenance_unit_;
}

const MaintenanceUnit& Aquarium::GetMaintenanceUnit() const {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return maintenance_unit_;
}

Schedule& Aquarium::GetSchedule() {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return schedule_;
}

const Schedule& Aquarium::GetSchedule() const {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return schedule_;
}

payment::PaymentContext& Aquarium::GetPaymentContext() {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return payment_context_;
}

const payment::PaymentContext& Aquarium::GetPaymentContext() const {
  if (!is_opened_) {
    throw utils::exceptions::ClosedAquariumError("Aquarium is closed.");
  }

  return payment_context_;
}

}  // namespace infrastructure