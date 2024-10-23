#ifndef SENSORJSONVISITOR_H
#define SENSORJSONVISITOR_H

#include "Model/SensorConstVisitorInterface.h"
#include <QJsonObject>

namespace Model::Converter {

class SensorJsonVisitor: public SensorConstVisitorInterface
{
private:
    QJsonObject json;
public:
    QJsonObject getJson() const;
    void visitBrightnessSensor(const BrightnessSensor&) override;
    void visitNoiseSensor(const NoiseSensor&) override;
    void visitTemperatureSensor(const TemperatureSensor&) override;
};

}
#endif // SENSORJSONVISITOR_H
