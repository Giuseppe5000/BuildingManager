#include "AddSensorDialog.h"
#include "Model/BrightnessSensor.h"
#include "Model/NoiseSensor.h"
#include "Model/TemperatureSensor.h"
#include <QDialogButtonBox>
#include <QLabel>
#include <QGridLayout>

namespace View::Dialog {

AddSensorDialog::AddSensorDialog(Model::Building& b, QWidget *parent)
    : QDialog(parent), building(b)
{
    setWindowTitle("Add sensor");
    setModal(true);

    QGridLayout* layout = new QGridLayout(this);

    manufactor = new QLineEdit;
    layout->addWidget(new QLabel("Manufactor"),0,0);
    layout->addWidget(manufactor,0,1);

    model = new QLineEdit;
    layout->addWidget(new QLabel("Model"),1,0);
    layout->addWidget(model,1,1);

    precision = new QDoubleSpinBox;
    layout->addWidget(new QLabel("Precision"),2,0);
    layout->addWidget(precision,2,1);
    precision->setRange(0.1, 100.0);
    precision->setValue(95.0);

    range = std::pair<QDoubleSpinBox*, QDoubleSpinBox*>(new QDoubleSpinBox, new QDoubleSpinBox);
    layout->addWidget(new QLabel("Range"),3,0);
    layout->addWidget(range.first,3,1);
    layout->addWidget(range.second,4,1);
    range.first->setFixedWidth(100);
    range.second->setFixedWidth(100);
    range.first->setRange(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());
    range.first->setValue(0.0);
    range.second->setRange(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());
    range.second->setValue(100.0);

    QComboBox* combo = new QComboBox;
    combo->addItem("Brightness");
    combo->addItem("Noise");
    combo->addItem("Temperature");
    layout->addWidget(new QLabel("Sensor type"),5,0);
    layout->addWidget(combo,5,1);

    stackedLayout = new QStackedLayout;

    QWidget* vF = new QWidget;
    visualField = new QSpinBox;
    QGridLayout* visualFieldLayout = new QGridLayout(vF);
    visualFieldLayout->addWidget(new QLabel("Visual Field"),0,0);
    visualFieldLayout->addWidget(visualField,0,1);
    visualField->setRange(1,360);
    visualField->setValue(320);
    stackedLayout->addWidget(vF);

    QWidget* mic = new QWidget;
    microphone = new QComboBox;
    QGridLayout* microphoneLayout = new QGridLayout(mic);
    microphoneLayout->addWidget(new QLabel("Micophone"),0,0);
    microphoneLayout->addWidget(microphone,0,1);
    microphone->addItem("capacitor");
    microphone->addItem("dynamic");
    microphone->addItem("tape");
    microphone->addItem("crystal");
    stackedLayout->addWidget(mic);

    QWidget* res = new QWidget;
    resistance = new QDoubleSpinBox;
    QGridLayout* resistanceLayout = new QGridLayout(res);
    resistanceLayout->addWidget(new QLabel("Resistance"),0,0);
    resistanceLayout->addWidget(resistance,0,1);
    resistance->setRange(0.1, std::numeric_limits<double>::max());
    resistance->setValue(100.0);
    stackedLayout->addWidget(res);

    layout->addLayout(stackedLayout,6,1);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout->addWidget(buttonBox,7,1);

    show();

    connect(combo, &QComboBox::currentIndexChanged, this, &AddSensorDialog::showType);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &AddSensorDialog::apply);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &AddSensorDialog::close);
}

void AddSensorDialog::showType(int index) {
    stackedLayout->setCurrentIndex(index);
}

void AddSensorDialog::apply() {
    switch(stackedLayout->currentIndex()) {
    case 0:
        building.addSensor(new Model::BrightnessSensor(manufactor->text().toStdString(), model->text().toStdString(), precision->value(), std::pair<double,double>(range.first->value(),range.second->value()), visualField->value()));
        break;

    case 1:
        building.addSensor(new Model::NoiseSensor(manufactor->text().toStdString(), model->text().toStdString(), precision->value(), std::pair<double,double>(range.first->value(),range.second->value()), static_cast<Model::NoiseSensor::Microphone>(microphone->currentIndex())));
        break;

    case 2:
        building.addSensor(new Model::TemperatureSensor(manufactor->text().toStdString(), model->text().toStdString(), precision->value(), std::pair<double,double>(range.first->value(),range.second->value()), resistance->value()));
        break;
    }
    close();
}

}
