#include "BrightnessSensor.h"
#include <random>
#include <cstdlib>

namespace Model {

BrightnessSensor::BrightnessSensor(const std::string& manufactor, const std::string& model, float precision, std::pair<double,double> range, unsigned short vF):
    Sensor(manufactor,model,precision,range), visualField(vF > 0 && vF <= 360 ? vF : 180) {}

unsigned short BrightnessSensor::getVisualField() const {
    return visualField;
}

void BrightnessSensor::setVisualField(unsigned short vF) {
    visualField = vF > 0 && vF <= 360 ? vF : 180;
}

std::vector<double> BrightnessSensor::simulation(unsigned int count) const {
    std::vector<double> measurements;

    std::pair<double,double> range = getRange();
    double min = range.first;
    double max = (range.second*(getVisualField()/360.0));
    int mean = rand()%int(max) + min;

    for (unsigned int i = 0; i < count; i++) {
        std::mt19937 gen;
        gen.seed(std::random_device{}());
        std::default_random_engine generator;
        std::normal_distribution<double> dist(mean, 100/getPrecision());
        measurements.push_back(dist(gen));
    }

    return measurements;
}

void BrightnessSensor::accept(SensorVisitorInterface& visitor) {
    visitor.visitBrightnessSensor(*this);
}

void BrightnessSensor::accept(SensorConstVisitorInterface& visitor) const {
    visitor.visitBrightnessSensor(*this);
}

}
