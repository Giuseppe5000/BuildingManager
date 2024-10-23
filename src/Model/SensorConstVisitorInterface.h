#ifndef SENSORCONSTVISITORINTERFACE_H
#define SENSORCONSTVISITORINTERFACE_H

namespace Model {

class BrightnessSensor;
class NoiseSensor;
class TemperatureSensor;

class SensorConstVisitorInterface
{
public:
    virtual ~SensorConstVisitorInterface() = default;
    virtual void visitBrightnessSensor(const BrightnessSensor&) = 0;
    virtual void visitNoiseSensor(const NoiseSensor&) = 0;
    virtual void visitTemperatureSensor(const TemperatureSensor&) = 0;
};

}
#endif // SENSORCONSTVISITORINTERFACE_H
