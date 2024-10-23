#include "EditTemperatureSensorDialog.h"
#include <QGridLayout>
#include <QLabel>
#include <QDialogButtonBox>

namespace View::Dialog {

EditTemperatureSensorDialog::EditTemperatureSensorDialog(Model::TemperatureSensor& s, QWidget *parent)
    : EditSensorDialogInterface(s, parent), sensor(s)
{
    QGridLayout* layout = getLayout();
    resistance = new QDoubleSpinBox;
    layout->addWidget(new QLabel("Resistance"),5,0);
    layout->addWidget(resistance,5,1);
    resistance->setRange(0.1, std::numeric_limits<double>::max());
    resistance->setValue(s.getResistance());

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout->addWidget(buttonBox,6,1);

    show();

    connect(buttonBox, &QDialogButtonBox::accepted, this, &EditTemperatureSensorDialog::apply);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &EditTemperatureSensorDialog::close);
}

void EditTemperatureSensorDialog::apply() {
    sensor.setResistance(resistance->value());
    EditSensorDialogInterface::apply();
    close();
}

}
