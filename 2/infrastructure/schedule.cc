#include "infrastructure/schedule.h"

#include <chrono>
#include <stdexcept>
#include <sstream>
#include <iomanip>

namespace infrastructure {

ScheduleEvent::ScheduleEvent(std::string name,
                             std::chrono::system_clock::time_point time,
                             std::function<void()> action)
    : name_(std::move(name)), time_(time), action_(std::move(action)) {
  if (name_.empty()) {
    throw std::invalid_argument("Schedule event name cannot be empty.");
  }
  if (!action_) {
    throw std::invalid_argument("Schedule event action cannot be empty.");
  }
}

void ScheduleEvent::ExecuteIfDue() const {
  auto now = std::chrono::system_clock::now();
  if (now >= time_) {
    action_();
  }
}

const std::string& ScheduleEvent::GetName() const noexcept { return name_; }

std::chrono::system_clock::time_point ScheduleEvent::GetTime() const noexcept { return time_; }

void Schedule::AddEvent(std::unique_ptr<ScheduleEvent> event) {
  if (!event) {
    throw std::invalid_argument("Cannot add null Schedule event.");
  }
  events_.emplace(event->GetTime(), std::move(event));
}

void Schedule::RemoveEvent(const std::string& name) {
  for (auto it = events_.begin(); it != events_.end();) {
    if (it->second->GetName() == name) {
      it = events_.erase(it);
    } else {
      ++it;
    }
  }
}

const ScheduleEvent* Schedule::GetNextEvent() const noexcept {
  if (events_.empty()) {
    return nullptr;
  }
  auto now = std::chrono::system_clock::now();
  for (const auto& [time, event] : events_) {
    if (time >= now) {
      return event.get();
    }
  }
  return nullptr;
}

std::vector<const ScheduleEvent*> Schedule::GetAllEvents() const noexcept {
  std::vector<const ScheduleEvent*> result;
  result.reserve(events_.size());
  for (const auto& [_, event] : events_) {
    result.push_back(event.get());
  }
  return result;
}

void Schedule::ExecuteDueEvents() const noexcept {
  auto now = std::chrono::system_clock::now();
  for (const auto& [time, event] : events_) {
    if (time <= now) {
      event->ExecuteIfDue();
    }
  }
}

std::string Schedule::GetSummary() const {
  std::ostringstream oss;

  oss << "=== Schedule Overview ===\n";
  for (const auto& [time, event] : events_) {
    std::time_t t = std::chrono::system_clock::to_time_t(time);
    oss << "- [" << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S") << "] "
        << event->GetName() << "\n";
  }

  return oss.str();
}

}  // namespace infrastructure
