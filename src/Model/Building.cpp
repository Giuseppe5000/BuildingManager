#include "Building.h"
#include <stdexcept>
#include <algorithm>

namespace Model {

void Building::notifyAll() const {
    for (auto observer : observers) {
        observer->notify(*this);
    }
}

Building::~Building() {
    for (auto sensor : sensors) {
        delete sensor;
    }
}

void Building::addSensor(Sensor* sensor) {
    sensors.push_back(sensor);
    notifyAll();
}

void Building::removeSensor(const Sensor& sensor) {
    auto it = std::find(sensors.begin(), sensors.end(), &sensor);
    delete *it;
    sensors.erase(it);
    notifyAll();
}

Sensor& Building::getSensor(unsigned int index) const {
    return *sensors.at(index);
}

unsigned int Building::getSize() const {
    return sensors.size();
}

void Building::clear() {
    for (auto sensor : sensors) {
        delete sensor;
    }
    sensors.clear();
    notifyAll();
}

void Building::registerObserver(BuildingObserverInterface* observer) {
    observers.push_back(observer);
}

}
