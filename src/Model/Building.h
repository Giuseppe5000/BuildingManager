#ifndef BUILDING_H
#define BUILDING_H

#include "Sensor.h"
#include "BuildingObserverInterface.h"

namespace Model {

class Building
{
private:
    std::vector<Sensor*> sensors;
    std::vector<BuildingObserverInterface*> observers;
    void notifyAll() const;
public:
    ~Building();
    void addSensor(Sensor*);
    void removeSensor(const Sensor&);
    Sensor& getSensor(unsigned int) const;
    unsigned int getSize() const;
    void clear();
    void registerObserver(BuildingObserverInterface*);
};

}
#endif // BUILDING_H
