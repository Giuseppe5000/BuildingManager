#include "EditBrightnessSensorDialog.h"
#include <QGridLayout>
#include <QLabel>
#include <QDialogButtonBox>

namespace View::Dialog {

EditBrightnessSensorDialog::EditBrightnessSensorDialog(Model::BrightnessSensor& s, QWidget* parent)
    : EditSensorDialogInterface(s, parent), sensor(s)
{
    QGridLayout* layout = getLayout();
    visualField = new QSpinBox;
    layout->addWidget(new QLabel("Visual Field"),5,0);
    layout->addWidget(visualField,5,1);
    visualField->setRange(1,360);
    visualField->setValue(sensor.getVisualField());

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout->addWidget(buttonBox,6,1);

    show();

    connect(buttonBox, &QDialogButtonBox::accepted, this, &EditBrightnessSensorDialog::apply);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &EditBrightnessSensorDialog::close);
}

void EditBrightnessSensorDialog::apply() {
    sensor.setVisualField(visualField->value());
    EditSensorDialogInterface::apply();
    close();
}

}
