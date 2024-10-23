#include "TemperatureSensor.h"
#include <random>
#include <cstdlib>

namespace Model {

TemperatureSensor::TemperatureSensor(const std::string& manufactor, const std::string& model, float precision, std::pair<double,double> range, double res):
    Sensor(manufactor,model,precision,range), resistance(res > 0.0 ? res : 10.0) {}

double TemperatureSensor::getResistance() const {
    return resistance;
}

void TemperatureSensor::setResistance(double res) {
    resistance = res > 0.0 ? res : 10.0;
}

std::vector<double> TemperatureSensor::simulation(unsigned int count) const {
    std::vector<double> measurements;

    std::pair<double,double> range = getRange();
    double min = range.first;
    double max = range.second;
    int mean = rand()%int(max) + min;

    for (unsigned int i = 0; i < count; i++) {
        std::mt19937 gen;
        gen.seed(std::random_device{}());
        std::default_random_engine generator;
        std::normal_distribution<double> dist(mean, 100/getPrecision());
        double measurement = dist(gen);
        measurement = getResistance()*2 >= measurement ? measurement : measurement/1.5;
        measurements.push_back(measurement);
    }

    return measurements;
}

void TemperatureSensor::accept(SensorVisitorInterface& visitor) {
    visitor.visitTemperatureSensor(*this);
}

void TemperatureSensor::accept(SensorConstVisitorInterface& visitor) const {
    visitor.visitTemperatureSensor(*this);
}

}
