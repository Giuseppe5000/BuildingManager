#ifndef EDITNOISESENSORDIALOG_H
#define EDITNOISESENSORDIALOG_H

#include "EditSensorDialogInterface.h"
#include "Model/NoiseSensor.h"
#include <QComboBox>

namespace View::Dialog {

class EditNoiseSensorDialog : public EditSensorDialogInterface
{
    Q_OBJECT
private:
    Model::NoiseSensor& sensor;
    QComboBox* microphone;
public:
    explicit EditNoiseSensorDialog(Model::NoiseSensor&, QWidget *parent = nullptr);
public slots:
    void apply();
};

}
#endif // EDITNOISESENSORDIALOG_H
