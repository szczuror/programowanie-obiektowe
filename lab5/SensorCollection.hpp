#pragma once
#include "Sensor.hpp"
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

class SensorCollection {
private:
  std::unordered_map<std::string, std::list<Sensor<double>>> sensorsByType;

public:
  void addSensor(const std::string &type, const Sensor<double> &sensor);
  const std::unordered_map<std::string, std::list<Sensor<double>>> &
  getSensorsByType() const;
  std::list<Sensor<double>> getAllSensors() const;

  void writeToStream(std::ostream &os) const;

  void reverseSensors();
  void removeShortSensors(const std::string &type, std::size_t minCount);
  double getTotalMinSum() const;
  std::list<Sensor<double>>
  getSensorsContaining(const std::string &keyword) const;
  std::optional<Sensor<double>> findHighestRMS() const;
};

std::ostream &operator<<(std::ostream &os, const SensorCollection &collection);
