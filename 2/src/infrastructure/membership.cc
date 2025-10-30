#include "infrastructure/membership.h"

#include <stdexcept>

#include "utils/exceptions/not_found_errors.h"
#include "utils/exceptions/already_exists_errors.h"
#include "utils/exceptions/unknown_type_errors.h"

namespace infrastructure {

Member::Member(std::string name, MembershipLevel level)
    : name_(std::move(name)), level_(level) {
  if (name_.empty()) {
    throw std::invalid_argument("Member name cannot be empty.");
  }
}

void Member::AddPoints(int points) {
  if (points < 0) {
    throw std::invalid_argument("Points must be positive.");
  }
  points_ += points;
}

void Member::RedeemPoints(int points) {
  if (points > points_) {
    throw std::invalid_argument("Not enough points.");
  }
  points_ -= points;
}

void Member::Upgrade() {
  switch (level_) {
    case MembershipLevel::kBasic:
      RedeemPoints(10);
      level_ = MembershipLevel::kSilver;
      break;
    case MembershipLevel::kSilver:
      RedeemPoints(25);
      level_ = MembershipLevel::kGold;
    case MembershipLevel::kGold:
      RedeemPoints(50);
      level_ = MembershipLevel::kPlatinum;
    case MembershipLevel::kPlatinum:
      throw std::runtime_error("User " + name_ + " already has a platinum membership level.");
    default:
      throw utils::exceptions::UnknownMembershipTypeError("Unknown membership level.");
      break;
  }
}

int Member::GetPoints() const noexcept { return points_; }

MembershipLevel Member::GetLevel() const noexcept { return level_; }

const std::string& Member::GetName() const noexcept { return name_; }

void MembershipSystem::RegisterMember(std::string name, MembershipLevel level) {
  if (members_.find(name) != members_.end()) {
    throw utils::exceptions::MemberAlreadyExistsError("Member " + name + " already exists.");
  }

  members_.emplace(name, Member(std::move(name), level));
}

void MembershipSystem::AddPoints(const std::string& name, int points) {
  auto it = members_.find(name);
  if (it == members_.end()) {
    throw utils::exceptions::MemberNotFoundError("Member " + name + " not found.");
  }

  it->second.AddPoints(points);
}

void MembershipSystem::RedeemPoints(const std::string& name, int points) {
  auto it = members_.find(name);
  if (it == members_.end()) {
    throw utils::exceptions::MemberNotFoundError("Member " + name + " not found.");
  }

  it->second.RedeemPoints(points);
}

int MembershipSystem::GetMemberPoints(const std::string& name) const {
  auto it = members_.find(name);
  if (it == members_.end()) {
    throw utils::exceptions::MemberNotFoundError("Member " + name + " not found.");
  }

  return it->second.GetPoints();
}

}  // namespace infrastructure