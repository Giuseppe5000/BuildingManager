#ifndef EDITBRIGHTNESSSENSORDIALOG_H
#define EDITBRIGHTNESSSENSORDIALOG_H

#include "EditSensorDialogInterface.h"
#include "Model/BrightnessSensor.h"
#include <QSpinBox>

namespace View::Dialog {

class EditBrightnessSensorDialog : public EditSensorDialogInterface
{
    Q_OBJECT
private:
    Model::BrightnessSensor& sensor;
    QSpinBox* visualField;
public:
    explicit EditBrightnessSensorDialog(Model::BrightnessSensor&, QWidget *parent = nullptr);
public slots:
    void apply();
};

}
#endif // EDITBRIGHTNESSSENSORDIALOG_H
