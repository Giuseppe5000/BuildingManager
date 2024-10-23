#include "SensorEditVisitor.h"
#include "View/Dialogs/EditSensor/EditBrightnessSensorDialog.h"
#include "View/Dialogs/EditSensor/EditNoiseSensorDialog.h"
#include "View/Dialogs/EditSensor/EditTemperatureSensorDialog.h"

namespace View {

SensorEditVisitor::SensorEditVisitor(QWidget* p): parent(p) {}

Dialog::EditSensorDialogInterface* SensorEditVisitor::getWidget() const {
    return widget;
}

void SensorEditVisitor::visitBrightnessSensor(Model::BrightnessSensor& s) {
    widget = new Dialog::EditBrightnessSensorDialog(s,parent);
}

void SensorEditVisitor::visitNoiseSensor(Model::NoiseSensor& s) {
    widget = new Dialog::EditNoiseSensorDialog(s,parent);
}

void SensorEditVisitor::visitTemperatureSensor(Model::TemperatureSensor& s) {
    widget = new Dialog::EditTemperatureSensorDialog(s,parent);
}

}
