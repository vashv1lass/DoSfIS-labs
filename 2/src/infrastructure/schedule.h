/**
 * @file infrastructure/schedule.h
 * @brief Declaration of the Schedule and ScheduleEvent classes.
 */

#ifndef INFRASTRUCTURE_SCHEDULE_H_
#define INFRASTRUCTURE_SCHEDULE_H_

#include <chrono>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>

/**
 * @brief Namespace for all infrastructure-related classes and functions.
 */
namespace infrastructure {

/**
 * @class ScheduleEvent
 * @brief Represents a scheduled event with a name, time, and action.
 */
class ScheduleEvent {
public:
  /**
   * @brief Constructor for ScheduleEvent class.
   * @param name The name of the event.
   * @param time The scheduled time for the event.
   * @param action The function to execute when the event is due.
   */
  ScheduleEvent(std::string name,
                std::chrono::system_clock::time_point time,
                std::function<void()> action);

  /**
   * @brief Executes the event's action if the scheduled time has passed.
   * @note This function checks the current time against the scheduled time.
   */
  void ExecuteIfDue() const;

  /**
   * @brief Retrieves the name of the event.
   * @return The name of the event as a string.
   */
  const std::string& GetName() const noexcept;

  /**
   * @brief Retrieves the scheduled time of the event.
   * @return The scheduled time as a system clock time point.
   */
  std::chrono::system_clock::time_point GetTime() const noexcept;

private:
  std::string name_;  /// The name of the event.
  std::chrono::system_clock::time_point time_;  /// The scheduled time for the event.
  std::function<void()> action_;  /// The function to execute when the event is due.
};

/**
 * @class Schedule
 * @brief Manages a collection of scheduled events.
 */
class Schedule {
public:
  /**
   * @brief Default constructor for Schedule class.
   */
  Schedule() = default;

  /**
   * @brief Copy constructor is deleted.
   */
  Schedule(const Schedule&) = delete;

  /**
   * @brief Assignment operator is deleted.
   */
  Schedule& operator=(const Schedule&) = delete;

  /**
   * @brief Adds an event to the schedule.
   * @param event Unique pointer to the event to add.
   */
  void AddEvent(std::unique_ptr<ScheduleEvent> event);

  /**
   * @brief Removes an event from the schedule by name.
   * @param name The name of the event to remove.
   */
  void RemoveEvent(const std::string& name);

  /**
   * @brief Retrieves the next scheduled event.
   * @return A pointer to the next event, or nullptr if no events exist.
   */
  const ScheduleEvent* GetNextEvent() const noexcept;

  /**
   * @brief Retrieves all scheduled events.
   * @return A vector containing pointers to all scheduled events.
   */
  std::vector<const ScheduleEvent*> GetAllEvents() const noexcept;

  /**
   * @brief Executes all events that are due based on the current time.
   * @note This function iterates through the events and executes the due ones.
   */
  void ExecuteDueEvents() const noexcept;

  /**
   * @brief Generates a summary of the schedule.
   * @return A string containing the schedule summary.
   */
  std::string GetSummary() const;

private:
  std::multimap<std::chrono::system_clock::time_point,
                std::unique_ptr<ScheduleEvent>> events_;  /// Collection of scheduled events, sorted by time.
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_SCHEDULE_H_