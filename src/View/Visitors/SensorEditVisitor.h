#ifndef SENSOREDITVISITOR_H
#define SENSOREDITVISITOR_H

#include "Model/SensorVisitorInterface.h"
#include "View/Dialogs/EditSensor/EditSensorDialogInterface.h"

namespace View {

class SensorEditVisitor: public Model::SensorVisitorInterface
{
private:
    Dialog::EditSensorDialogInterface* widget;
    QWidget* parent;
public:
    SensorEditVisitor(QWidget*);
    Dialog::EditSensorDialogInterface* getWidget() const;
    void visitBrightnessSensor(Model::BrightnessSensor&) override;
    void visitNoiseSensor(Model::NoiseSensor&) override;
    void visitTemperatureSensor(Model::TemperatureSensor&) override;
};

}
#endif // SENSOREDITVISITOR_H
