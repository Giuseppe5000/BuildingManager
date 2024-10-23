#include "EditSensorDialogInterface.h"
#include <QGridLayout>
#include <QLabel>
#include <QDialogButtonBox>

namespace View::Dialog {

EditSensorDialogInterface::EditSensorDialogInterface(Model::Sensor& s, QWidget *parent)
    : QDialog(parent), sensor(s)
{
    setWindowTitle("Edit sensor");

    layout = new QGridLayout(this);

    manufactor = new QLineEdit;
    layout->addWidget(new QLabel("Manufactor"),0,0);
    layout->addWidget(manufactor,0,1);
    manufactor->setText(QString::fromStdString(sensor.getManufactor()));

    model = new QLineEdit;
    layout->addWidget(new QLabel("Model"),1,0);
    layout->addWidget(model,1,1);
    model->setText(QString::fromStdString(sensor.getModel()));

    precision = new QDoubleSpinBox;
    layout->addWidget(new QLabel("Precision"),2,0);
    layout->addWidget(precision,2,1);
    precision->setRange(0.1, 100.0);
    precision->setValue(sensor.getPrecision());

    range = std::pair<QDoubleSpinBox*,QDoubleSpinBox*>(new QDoubleSpinBox, new QDoubleSpinBox);
    layout->addWidget(new QLabel("Range"),3,0);
    layout->addWidget(range.first,3,1);
    layout->addWidget(range.second,4,1);
    range.first->setFixedWidth(100);
    range.second->setFixedWidth(100);
    range.first->setRange(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());
    range.first->setValue(sensor.getRange().first);
    range.second->setRange(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());
    range.second->setValue(sensor.getRange().second);
}

QGridLayout* EditSensorDialogInterface::getLayout() const {
    return layout;
}

void EditSensorDialogInterface::apply() {
    sensor.setManufactor(manufactor->text().toStdString());
    sensor.setModel(model->text().toStdString());
    sensor.setPrecision(precision->value());
    sensor.setRange(std::pair<double,double>(range.first->value(), range.second->value()));

    emit editSensor(sensor);
}

EditSensorDialogInterface::~EditSensorDialogInterface() = default;

}
