#ifndef INFRASTRUCTURE_ECOSYSTEM_H_
#define INFRASTRUCTURE_ECOSYSTEM_H_

#include <memory>
#include <string>
#include <vector>

namespace animals {

class Animal;

}  // namespace animals

namespace infrastructure {

class Ecosystem {
public:
  Ecosystem() = default;

  void AddAnimal(std::unique_ptr<animals::Animal> animal);

  std::vector<std::string> GetStatusReport() const;
  std::size_t GetCount() const noexcept;

private:
  std::vector<std::unique_ptr<animals::Animal>> animals_;
};

}  // namespace infrastructure

#endif  // INFRASTRUCTURE_ECOSYSTEM_H_