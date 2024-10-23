#ifndef EDITSENSORDIALOGINTERFACE_H
#define EDITSENSORDIALOGINTERFACE_H

#include "Model/Sensor.h"
#include <QDialog>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QComboBox>
#include <QGridLayout>

namespace View::Dialog {

class EditSensorDialogInterface : public QDialog
{
    Q_OBJECT
private:
    Model::Sensor& sensor;
    QLineEdit* manufactor;
    QLineEdit* model;
    QDoubleSpinBox* precision;
    std::pair<QDoubleSpinBox*, QDoubleSpinBox*> range;
    QGridLayout* layout;
public:
    explicit EditSensorDialogInterface(Model::Sensor&, QWidget *parent = nullptr);
    virtual ~EditSensorDialogInterface() = 0;
    QGridLayout* getLayout() const;
public slots:
    void apply();
signals:
    void editSensor(Model::Sensor&);
};

}
#endif // EDITSENSORDIALOGINTERFACE_H
