/**
 * @file infrastructure/membership.h
 * @brief Declaration of the MembershipSystem class and related components.
 */

#ifndef INFRASTRUCTURE_MEMBERSHIP_H_
#define INFRASTRUCTURE_MEMBERSHIP_H_

#include <string>
#include <unordered_map>

/**
 * @brief Namespace for all infrastructure-related classes and functions.
 */
namespace infrastructure {

/**
 * @enum MembershipLevel
 * @brief Enumerates the possible membership levels.
 */
enum class MembershipLevel {
  kBasic,     /// Basic membership level.
  kSilver,    /// Silver membership level.
  kGold,      /// Gold membership level.
  kPlatinum   /// Platinum membership level.
};

/**
 * @class Member
 * @brief Represents a member of the aquarium membership system.
 */
class Member {
public:
  /**
   * @brief Constructor for Member class.
   * @param name The name of the member.
   * @param level The membership level of the member.
   */
  Member(std::string name, MembershipLevel level);

  /**
   * @brief Adds points to the member's account.
   * @param points The number of points to add.
   */
  void AddPoints(int points);

  /**
   * @brief Redeems points from the member's account.
   * @param points The number of points to redeem.
   */
  void RedeemPoints(int points);

  /**
   * @brief Upgrades the member's membership level based on accumulated points.
   * @note The upgrade logic depends on the current level and points.
   */
  void Upgrade();

  /**
   * @brief Retrieves the number of points the member has.
   * @return The number of points.
   */
  int GetPoints() const noexcept;

  /**
   * @brief Retrieves the membership level of the member.
   * @return The membership level.
   */
  MembershipLevel GetLevel() const noexcept;

  /**
   * @brief Retrieves the name of the member.
   * @return The name of the member as a string.
   */
  const std::string& GetName() const noexcept;

private:
  std::string name_;              /// The name of the member.
  MembershipLevel level_;         /// The membership level of the member.
  int points_{0};                 /// The number of points accumulated by the member.
};

/**
 * @class MembershipSystem
 * @brief Manages the membership system for the aquarium.
 */
class MembershipSystem {
public:
  /**
   * @brief Default constructor for MembershipSystem class.
   */
  MembershipSystem() = default;

  /**
   * @brief Registers a new member in the system.
   * @param name The name of the member to register.
   * @param level The initial membership level of the member.
   */
  void RegisterMember(std::string name, MembershipLevel level);

  /**
   * @brief Adds points to a member's account.
   * @param name The name of the member to add points for.
   * @param points The number of points to add.
   */
  void AddPoints(const std::string& name, int points);

  /**
   * @brief Redeems points from a member's account.
   * @param name The name of the member to redeem points for.
   * @param points The number of points to redeem.
   */
  void RedeemPoints(const std::string& name, int points);

  /**
   * @brief Retrieves the number of points for a specific member.
   * @param name The name of the member to query.
   * @return The number of points the member has.
   */
  int GetMemberPoints(const std::string& name) const;

private:
  std::unordered_map<std::string, Member> members_;  /// Map of members by name.
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_MEMBERSHIP_H_