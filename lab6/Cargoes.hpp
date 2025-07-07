#pragma once

#include <cstdint>
#include <string>

class Cargo {
protected:
  const uint64_t ID;
  const std::string name;
  static uint64_t nextID;

public:
  uint64_t getID() const { return ID; }
  const std::string &getName() const { return name; }
  virtual std::string getDescription() const = 0;
  virtual double getWeight() const = 0;

  Cargo(const std::string &name) : name(name), ID(nextID++) {}
  virtual ~Cargo() = default;
};

uint64_t Cargo::nextID = 1;

class RawMaterialCargo : public Cargo {
  double purityPercentage;
  double weight;

public:
  RawMaterialCargo(const std::string &name, double weight, double purity)
      : Cargo(name), purityPercentage(purity), weight(weight) {}

  std::string getDescription() const override {
    return name + " (ID: " + std::to_string(ID) + ") - Raw Material: Purity " +
           std::to_string(purityPercentage) + "%";
  }

  double getWeight() const override { return weight; }
};

class ManufacturedGoodsCargo : public Cargo {
  unsigned int unitCount;
  double weightPerUnit;

public:
  ManufacturedGoodsCargo(const std::string &name, unsigned int count,
                         double weightPU)
      : Cargo(name), unitCount(count), weightPerUnit(weightPU) {}

  std::string getDescription() const override {
    return name + " (ID: " + std::to_string(ID) +
           ") - Manufactured Goods: " + std::to_string(unitCount) + " units";
  }

  double getWeight() const override { return unitCount * weightPerUnit; }
};

enum class DangerLevel { LOW = 0, MEDIUM = 1, HIGH = 2, CRITICAL = 3 };

class HazardousWasteCargo : public Cargo {
private:
    DangerLevel dangerLevel;
    double weight;

    std::string dangerLevelToString() const {
        switch(dangerLevel) {
            case DangerLevel::LOW: return "Low";
            case DangerLevel::MEDIUM: return "Medium";
            case DangerLevel::HIGH: return "High";
            case DangerLevel::CRITICAL: return "CRITICAL";
            default: return "Unknown";
        }
    }

public:
    HazardousWasteCargo(const std::string& name, double weight, DangerLevel danger)
        : Cargo(name), dangerLevel(danger), weight(weight) {}

    std::string getDescription() const override {
        return name + " (ID: " + std::to_string(ID) + ") - Hazardous Waste: Danger Level " + dangerLevelToString();
    }

    double getWeight() const override { return weight; }

    DangerLevel getDangerLevel() const { return dangerLevel; }
};

