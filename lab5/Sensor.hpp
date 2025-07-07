#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <optional>
#include <algorithm>
#include <numeric>
#include <cmath>

template<typename T>
class Sensor{
    public:
        struct Identity{
        std::string hardwareID;
        std::string type;

            Identity(const std::string& hardwareID, const std::string& type) : hardwareID(hardwareID), type(type) {}
        };

    private: 
        std::string label;
        std::variant<Identity, std::string> source;
        std::optional<std::string> unit;
        std::vector<T> measurements;

    public:
        Sensor(const std::string& label, const std::variant<Identity, std::string> source, const std::optional<std::string> unit = std::nullopt)
        : label(label), source(source), unit(unit), measurements() {}


    const std::string& getLabel() const {return label;}
    const std::optional<std::string>& getUnit() const {return unit;}
    const std::variant<Identity, std::string>& getSource() const {return source;}
    const std::vector<T>& getMeasurements() const {return measurements;}


    double getRMS() const {
        const auto& measurements = getMeasurements();
        if(measurements.empty()) {
            return T(0);
        }
        double squareSum = std::accumulate(measurements.begin(), measurements.end(), 0.0,
            [](double sum, const T& value) {
                return sum + static_cast<double>(value) * static_cast<double>(value);
            });
        return std::sqrt(squareSum / measurements.size());
    }

    double getMin() const {
        const auto& measurements = getMeasurements();
        if(measurements.empty()) {
            return T(0);
        }
        auto min_it = std::min_element(measurements.begin(), measurements.end());
        return static_cast<double>(*min_it);
    }

    bool operator<(const Sensor& other)const {
        if(label == other.label) {
            return measurements.size() < other.measurements.size();
        }
        return label < other.label;
    }

    bool operator!=(const Sensor& other) const {
        return label != other.label;
    }

    Sensor& operator<<(const T& measurement) {
        measurements.push_back(measurement);
        return *this;
    }

    bool operator>(const Sensor& other) const {
        if (label == other.label) {
            return measurements.size() > other.measurements.size();
        }
        return label > other.label;
    }

    void writeToStream(std::ostream& os) const {
        os << label << " [";
        if (std::holds_alternative<Identity>(source)) {
            const auto& id = std::get<Identity>(source);
            os << id.hardwareID << ", " << id.type;
        } else {
            os << std::get<std::string>(source);
        }
        os << "] RMS: " << getRMS() << ", Min: " << getMin() << "\n";

        if (unit.has_value()) {
            os << "Unit: " << unit.value() << "\n";
        }
    }

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Sensor<T>& sensor) {
    sensor.writeToStream(os);
    return os;
}