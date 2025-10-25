#ifndef INFRASTRUCTURE_MEMBERSHIP_H_
#define INFRASTRUCTURE_MEMBERSHIP_H_

#include <string>
#include <unordered_map>

namespace infrastructure {

enum class MembershipLevel {
  kBasic,
  kSilver,
  kGold,
  kPlatinum
};

class Member {
public:
  Member(std::string name, MembershipLevel level);

  void AddPoints(int points);
  void RedeemPoints(int points);
  void Upgrade();

  int GetPoints() const noexcept;
  MembershipLevel GetLevel() const noexcept;
  const std::string& GetName() const noexcept;

private:
  std::string name_;
  MembershipLevel level_;
  int points_{0};
};

class MembershipSystem {
public:
  MembershipSystem() = default;

  void RegisterMember(std::string name, MembershipLevel level);

  void AddPoints(const std::string& name, int points);
  void RedeemPoints(const std::string& name, int points);
  int GetMemberPoints(const std::string& name) const;

private:
  std::unordered_map<std::string, Member> members_;
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_MEMBERSHIP_H_