#include "NoiseSensor.h"
#include <random>
#include <cstdlib>

namespace Model {

NoiseSensor::NoiseSensor(const std::string& manufactor, const std::string& model, float precision, std::pair<double,double> range, Microphone mic):
    Sensor(manufactor, model, precision, range), microphone(mic) {}

NoiseSensor::Microphone NoiseSensor::getMicrophone() const {
    return microphone;
}

void NoiseSensor::setMicrophone(Microphone mic) {
    microphone = mic;
}

std::vector<double> NoiseSensor::simulation(unsigned int count) const {
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
        double measurement = (dist(gen));

        switch (getMicrophone()) {
        case capacitor:
            measurement = measurement * 1.1;
            break;
        case dynamic:
            measurement = measurement * 1.05;
            break;
        case tape:
            measurement = measurement * 1.15;
            break;
        case crystal:
            break;
        default:
            break;
        }

        measurements.push_back(measurement);
    }

    return measurements;
}

void NoiseSensor::accept(SensorVisitorInterface& visitor) {
    visitor.visitNoiseSensor(*this);
}

void NoiseSensor::accept(SensorConstVisitorInterface& visitor) const {
    visitor.visitNoiseSensor(*this);
}

}
