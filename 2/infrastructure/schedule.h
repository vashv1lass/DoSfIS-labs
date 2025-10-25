#ifndef INFRASTRUCTURE_SCHEDULE_H_
#define INFRASTRUCTURE_SCHEDULE_H_

#include <chrono>
#include <functional>
#include <string>
#include <memory>
#include <map>

namespace infrastructure {

class ScheduleEvent {
public:
  ScheduleEvent(std::string name,
                std::chrono::system_clock::time_point time,
                std::function<void()> action);

  void ExecuteIfDue() const;

  const std::string& GetName() const noexcept;
  std::chrono::system_clock::time_point GetTime() const noexcept;

private:
  std::string name_;
  std::chrono::system_clock::time_point time_;
  std::function<void()> action_;
};

class Schedule {
public:
  Schedule() = default;

  Schedule(const Schedule&) = delete;
  Schedule& operator=(const Schedule&) = delete;

  void AddEvent(std::unique_ptr<ScheduleEvent> event);
  void RemoveEvent(const std::string& name);
  const ScheduleEvent* GetNextEvent() const noexcept;
  std::vector<const ScheduleEvent*> GetAllEvents() const noexcept;

  void ExecuteDueEvents() const noexcept;
  std::string GetSummary() const;

private:
  std::multimap<std::chrono::system_clock::time_point,
                std::unique_ptr<ScheduleEvent>> events_;
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_SCHEDULE_H_