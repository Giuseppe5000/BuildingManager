#include "SensorItem.h"
#include "Visitors/SensorEditVisitor.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace View {

SensorItem::SensorItem(Model::Sensor& s, QWidget *parent)
    : QWidget(parent), sensor(s)
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    sensorBtn = new QPushButton(QString::fromStdString(sensor.getManufactor() + " " + sensor.getModel()));
    sensorBtn->setObjectName("sensorBtn");
    sensorBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sensorBtn->setMinimumWidth(120);
    mainLayout->addWidget(sensorBtn);
    mainLayout->setStretch(0, 7);

    QVBoxLayout* commandsLayout = new QVBoxLayout;

    editBtn = new QPushButton(QIcon(":/assets/icons/edit.svg"), "Edit");
    editBtn->setObjectName("editBtn");
    editBtn->setMaximumSize(80,80);
    editBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    commandsLayout->addWidget(editBtn);

    deleteBtn = new QPushButton(QIcon(":/assets/icons/delete.svg"), "Delete");
    deleteBtn->setObjectName("deleteBtn");
    deleteBtn->setMaximumSize(80,80);
    deleteBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    commandsLayout->addWidget(deleteBtn);

    connect(sensorBtn, &QPushButton::clicked, this, [this] { emit selectSensor(sensor); });
    connect(editBtn, &QPushButton::clicked, this, &SensorItem::editClicked);
    connect(deleteBtn, &QPushButton::clicked, this, [this] { emit deleteSensor(sensor); });

    mainLayout->addLayout(commandsLayout);
    mainLayout->setSpacing(0);
}

void SensorItem::editClicked() {
    SensorEditVisitor visitor(this);
    sensor.accept(visitor);
    connect(visitor.getWidget(), &Dialog::EditSensorDialogInterface::editSensor, this, &SensorItem::editSensor);
    connect(visitor.getWidget(), &Dialog::EditSensorDialogInterface::editSensor, this, &SensorItem::editRefresh);
}

void SensorItem::editRefresh(const Model::Sensor& sensor) {
    sensorBtn->setText(QString::fromStdString(sensor.getManufactor() + " " + sensor.getModel()));
}

}
