/**
 * @file infrastructure/aquarium.h
 * @brief Declaration of the Aquarium singleton class.
 */

#ifndef INFRASTRUCTURE_AQUARIUM_H_
#define INFRASTRUCTURE_AQUARIUM_H_

#include <memory>
#include <string>

#include "infrastructure/ecosystem.h"
#include "infrastructure/human_resources.h"
#include "infrastructure/medical_department.h"
#include "infrastructure/membership.h"
#include "infrastructure/maintenance.h"
#include "infrastructure/schedule.h"
#include "payment/context.h"

/**
 * @brief Namespace for all infrastructure-related classes and functions.
 */
namespace infrastructure {

/**
 * @class Aquarium
 * @brief Singleton class representing the aquarium facility.
 */
class Aquarium {
public:
  /**
   * @brief Gets the singleton instance of the Aquarium.
   * @return A reference to the Aquarium instance.
   */
  static Aquarium& Instance();

  /**
   * @brief Copy constructor is deleted.
   */
  Aquarium(const Aquarium&) = delete;

  /**
   * @brief Assignment operator is deleted.
   */
  Aquarium& operator=(const Aquarium&) = delete;

  /**
   * @brief Move constructor is deleted.
   */
  Aquarium(Aquarium&&) = delete;

  /**
   * @brief Move assignment operator is deleted.
   */
  Aquarium& operator=(Aquarium&&) = delete;

  /**
   * @brief Opens the aquarium.
   * @note This function performs the necessary operations to open the aquarium.
   */
  void Open() noexcept;

  /**
   * @brief Closes the aquarium.
   * @note This function performs the necessary operations to close the aquarium.
   */
  void Close() noexcept;

  /**
   * @brief Retrieves the ecosystem component of the aquarium.
   * @return A reference to the Ecosystem.
   */
  Ecosystem& GetEcosystem();

  /**
   * @brief Retrieves the ecosystem component of the aquarium.
   * @return A const reference to the Ecosystem.
   */
  const Ecosystem& GetEcosystem() const;

  /**
   * @brief Retrieves the human resources component of the aquarium.
   * @return A reference to the HumanResources.
   */
  HumanResources& GetHumanResources();

  /**
   * @brief Retrieves the human resources component of the aquarium.
   * @return A const reference to the HumanResources.
   */
  const HumanResources& GetHumanResources() const;

  /**
   * @brief Retrieves the membership system component of the aquarium.
   * @return A reference to the MembershipSystem.
   */
  MembershipSystem& GetMembershipSystem();

  /**
   * @brief Retrieves the membership system component of the aquarium.
   * @return A const reference to the MembershipSystem.
   */
  const MembershipSystem& GetMembershipSystem() const;

  /**
   * @brief Retrieves the maintenance unit component of the aquarium.
   * @return A reference to the MaintenanceUnit.
   */
  MaintenanceUnit& GetMaintenanceUnit();

  /**
   * @brief Retrieves the maintenance unit component of the aquarium.
   * @return A const reference to the MaintenanceUnit.
   */
  const MaintenanceUnit& GetMaintenanceUnit() const;

  /**
   * @brief Retrieves the schedule component of the aquarium.
   * @return A reference to the Schedule.
   */
  Schedule& GetSchedule();

  /**
   * @brief Retrieves the schedule component of the aquarium.
   * @return A const reference to the Schedule.
   */
  const Schedule& GetSchedule() const;

  /**
   * @brief Retrieves the payment context component of the aquarium.
   * @return A reference to the PaymentContext.
   */
  payment::PaymentContext& GetPaymentContext();

  /**
   * @brief Retrieves the payment context component of the aquarium.
   * @return A const reference to the PaymentContext.
   */
  const payment::PaymentContext& GetPaymentContext() const;

private:
  /**
   * @brief Private constructor for the singleton pattern.
   */
  Aquarium();

  /**
   * @brief Destructor for the Aquarium class.
   */
  ~Aquarium() = default;

  Ecosystem ecosystem_;  /// The ecosystem component of the aquarium.
  HumanResources human_resources_;  /// The human resources component of the aquarium.
  MedicalDepartment medical_department_;  /// The medical department component of the aquarium.
  MembershipSystem membership_system_;  /// The membership system component of the aquarium.
  MaintenanceUnit maintenance_unit_;  /// The maintenance unit component of the aquarium.
  Schedule schedule_;  /// The schedule component of the aquarium.
  payment::PaymentContext payment_context_;  /// The payment context component of the aquarium.

  bool is_opened_;  /// Indicates whether the aquarium is currently opened.
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_AQUARIUM_H_