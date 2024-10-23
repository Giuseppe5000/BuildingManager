#include "EditNoiseSensorDialog.h"
#include <QLabel>
#include <QDialogButtonBox>

namespace View::Dialog {

EditNoiseSensorDialog::EditNoiseSensorDialog(Model::NoiseSensor& s, QWidget *parent)
    : EditSensorDialogInterface(s, parent), sensor(s)
{
    QGridLayout* layout = getLayout();
    microphone = new QComboBox;
    layout->addWidget(new QLabel("Micophone"),5,0);
    layout->addWidget(microphone,5,1);
    microphone->addItem("capacitor");
    microphone->addItem("dynamic");
    microphone->addItem("tape");
    microphone->addItem("crystal");
    microphone->setCurrentIndex(s.getMicrophone());

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout->addWidget(buttonBox,6,1);

    show();

    connect(buttonBox, &QDialogButtonBox::accepted, this, &EditNoiseSensorDialog::apply);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &EditNoiseSensorDialog::close);
}

void EditNoiseSensorDialog::apply() {
    sensor.setMicrophone(static_cast<Model::NoiseSensor::Microphone>(microphone->currentIndex()));
    EditSensorDialogInterface::apply();
    close();
}

}
