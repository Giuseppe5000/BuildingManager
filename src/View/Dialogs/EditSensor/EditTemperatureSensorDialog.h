#ifndef EDITTEMPERATURESENSORDIALOG_H
#define EDITTEMPERATURESENSORDIALOG_H

#include "EditSensorDialogInterface.h"
#include "Model/TemperatureSensor.h"
#include <QDoubleSpinBox>

namespace View::Dialog {

class EditTemperatureSensorDialog : public EditSensorDialogInterface
{
    Q_OBJECT
private:
    Model::TemperatureSensor& sensor;
    QDoubleSpinBox* resistance;
public:
    explicit EditTemperatureSensorDialog(Model::TemperatureSensor&, QWidget *parent = nullptr);
public slots:
    void apply();
};

}
#endif // EDITTEMPERATURESENSORDIALOG_H
