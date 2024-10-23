#ifndef SENSORVISITORINTERFACE_H
#define SENSORVISITORINTERFACE_H

namespace Model {

class BrightnessSensor;
class NoiseSensor;
class TemperatureSensor;

class SensorVisitorInterface
{
public:
    virtual ~SensorVisitorInterface() = default;
    virtual void visitBrightnessSensor(BrightnessSensor&) = 0;
    virtual void visitNoiseSensor(NoiseSensor&) = 0;
    virtual void visitTemperatureSensor(TemperatureSensor&) = 0;
};

}
#endif // SENSORVISITORINTERFACE_H
