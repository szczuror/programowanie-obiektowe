#include "SensorCollection.hpp"

#include <algorithm>
#include <numeric>  
#include <iterator> 


void SensorCollection::addSensor(const std::string& type, const Sensor<double>& sensor) {
    sensorsByType[type].push_back(sensor);
}

const std::unordered_map<std::string, std::list<Sensor<double>>>& SensorCollection::getSensorsByType() const {
    return sensorsByType;
}

std::list<Sensor<double>> SensorCollection::getAllSensors() const {
    std::list<Sensor<double>> all;
    for (const auto& [type, sensors] : sensorsByType) {
        all.insert(all.end(), sensors.begin(), sensors.end());
    }
    return all;
}

void SensorCollection::writeToStream(std::ostream& os) const {
    for (const auto& [type, sensors] : sensorsByType) {
        os << "=== " << type << " ===\n";
        for (const auto& sensor : sensors) {
            sensor.writeToStream(os);
            os << "\n";
        }
    }
}

void SensorCollection::reverseSensors() {
    for (auto& [type, sensors] : sensorsByType) {
        sensors.reverse(); 
    }
}

void SensorCollection::removeShortSensors(const std::string& type, std::size_t minCount) {
    auto it = sensorsByType.find(type);
    if (it != sensorsByType.end()) {
        it->second.remove_if([minCount](const Sensor<double>& sensor) {
            return sensor.getMeasurements().size() < minCount;
        });
    }
}

std::ostream& operator<<(std::ostream& os, const SensorCollection& collection) {
    collection.writeToStream(os);
    return os;
}

double SensorCollection::getTotalMinSum() const {
    auto allSensors = getAllSensors();
    return std::accumulate(allSensors.begin(), allSensors.end(), 0.0,
        [](double sum, const Sensor<double>& sensor) {
            return sum + sensor.getMin();
        });
}

std::list<Sensor<double>> SensorCollection::getSensorsContaining(const std::string& keyword) const {
    auto allSensors = getAllSensors();
    std::list<Sensor<double>> result;

    std::copy_if(allSensors.begin(), allSensors.end(), std::back_inserter(result),
        [&keyword](const Sensor<double>& sensor) {
            return sensor.getLabel().find(keyword) != std::string::npos;
        });

    return result;
}

std::optional<Sensor<double>> SensorCollection::findHighestRMS() const {
    auto allSensors = getAllSensors();
    if (allSensors.empty()) return std::nullopt;

    auto it = std::max_element(allSensors.begin(), allSensors.end(),
        [](const Sensor<double>& a, const Sensor<double>& b) {
            return a.getRMS() < b.getRMS();
        });

    return *it;
}
