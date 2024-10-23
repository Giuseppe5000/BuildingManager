#ifndef BUILDINGOBSERVERINTERFACE_H
#define BUILDINGOBSERVERINTERFACE_H

namespace Model {

class Building;

class BuildingObserverInterface
{
public:
    virtual ~BuildingObserverInterface() = default;
    virtual void notify(const Building&) = 0;
};

}
#endif // BUILDINGOBSERVERINTERFACE_H
