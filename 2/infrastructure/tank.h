#ifndef INFRASTRUCTURE_TANK_H_
#define INFRASTRUCTURE_TANK_H_

#include <memory>
#include <stdexcept>
#include <vector>

namespace animals {

class Animal;

} // namespace animals

namespace infrastructure {

class Tank {
public:
  Tank(double depth, double volume);

  void AddAnimal(std::shared_ptr<animals::Animal> animal);
  void ShowAll() const noexcept;

  int GetID() const noexcept;
  double GetDepth() const noexcept;
  double GetVolume() const noexcept;
  bool IsClean() const noexcept;

  void SetDepth(double depth);
  void SetVolume(double volume);
  void MarkClean() noexcept;
  void MarkDirty() noexcept;

private:
  int id_;

  double depth_;
  double volume_;

  bool is_clean_;
  
  std::vector<std::shared_ptr<animals::Animal>> animals_;
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_TANK_H_