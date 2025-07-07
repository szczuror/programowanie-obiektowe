#pragma once

#include "Cargoes.hpp"
#include <iostream>
#include <vector>

class TransportVessel {
protected:
  std::string id;
  std::vector<Cargo *> cargoList;
  double currentLoad;
  double maxCapacity;

public:
  TransportVessel(const std::string &id, double capacity)
      : id(id), currentLoad(0), maxCapacity(capacity) {}

  virtual ~TransportVessel() = default;

  double getCurrentLoad() const { return currentLoad; }
  const std::string &getID() const { return id; }
  const std::vector<Cargo *> &getLoadedCargo() const { return cargoList; }
  virtual double getMaxCapacity() const { return maxCapacity; }

  virtual bool loadCargo(Cargo *cargo) {
    double cargoWeight = cargo->getWeight();
    auto *dangerous = dynamic_cast<HazardousWasteCargo *>(cargo);
    if (currentLoad + cargoWeight > maxCapacity) {
      std::cout << id << " cannot load " << cargo->getDescription()
                << ". Exceeds capacity of " << maxCapacity << " units.\n";
      return false;
    }

    cargoList.push_back(cargo);
    currentLoad += cargoWeight;
    if (dangerous == nullptr) {
      std::cout << id << " loaded " << cargo->getDescription()
                << ". Current load: " << currentLoad << " / " << maxCapacity
                << "\n";
    } else {
      std::cout << "WARNING: Hazardous Waste Cargo (" << dangerous->getName()
                << ", Danger Level: "
                << static_cast<int>(dangerous->getDangerLevel())
                << ") loaded!\n";
    }
    return true;
  }
};

class Freighter : public TransportVessel {
public:
  Freighter(const std::string &id, double capacity)
      : TransportVessel(id, capacity) {}

  bool loadCargo(Cargo *cargo) override {
    if (auto *hazardous = dynamic_cast<HazardousWasteCargo *>(cargo)) {
      std::cout << "  WARNING: Hazardous Waste Cargo (" << hazardous->getName()
                << ", Danger Level: "
                << static_cast<int>(hazardous->getDangerLevel())
                << ") loaded!\n";
    }
    return TransportVessel::loadCargo(cargo);
  }
}
;


class ScoutShip : public TransportVessel {
public:
    ScoutShip(const std::string& id, double capacity)
        : TransportVessel(id, capacity) {}

    bool loadCargo(Cargo* cargo) override {
        if (auto* hazardous = dynamic_cast<HazardousWasteCargo*>(cargo)) {
            if (hazardous->getDangerLevel() != DangerLevel::LOW) {
                std::cout << id << " cannot load " << hazardous->getDescription()
                          << ". Too dangerous to ship!\n";
                return false;
            }
            std::cout << "  WARNING: Hazardous Waste Cargo (" << hazardous->getName()
                      << ", Danger Level: " << static_cast<int>(hazardous->getDangerLevel())
                      << ") loaded!\n";
        }
        
        double cargoWeight = cargo->getWeight();
        if (cargoWeight > 200.0) {
            std::cout << id << " cannot load " << cargo->getDescription()
                      << ". Exceeds maximum single cargo weight of 200 units.\n";
            return false;
        }
       
        return TransportVessel::loadCargo(cargo);
    }
};
