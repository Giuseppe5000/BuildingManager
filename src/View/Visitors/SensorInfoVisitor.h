#ifndef SENSORINFOVISITOR_H
#define SENSORINFOVISITOR_H

#include "Model/SensorConstVisitorInterface.h"
#include <QWidget>

namespace View {

class SensorInfoVisitor: public Model::SensorConstVisitorInterface
{
private:
    QWidget* widget;
public:
    QWidget* getWidget() const;
    void visitBrightnessSensor(const Model::BrightnessSensor&) override;
    void visitNoiseSensor(const Model::NoiseSensor&) override;
    void visitTemperatureSensor(const Model::TemperatureSensor&) override;
};

}
#endif // SENSORINFOVISITOR_H
