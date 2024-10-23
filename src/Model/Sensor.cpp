#include "Sensor.h"

namespace Model {

Sensor::Sensor(const std::string& man, const std::string& mod, float prec, std::pair<double,double> r):
    manufactor(man), model(mod), precision(prec > 0.0 && prec <= 100.0 ? prec : 50.0), range(r) {}

std::string Sensor::getManufactor() const {
    return manufactor;
}

std::string Sensor::getModel() const {
    return model;
}

float Sensor::getPrecision() const {
    return precision;
}

void Sensor::setManufactor(const std::string& man) {
    manufactor = man;
}

void Sensor::setModel(const std::string& mod) {
    model = mod;
}

void Sensor::setPrecision(float prec) {
    precision = prec > 0.0 && prec <= 100.0 ? prec : 50.0;
}

void Sensor::setRange(std::pair<double,double> r) {
    range = r;
}

std::pair<double,double> Sensor::getRange() const {
    return range;
}

}
