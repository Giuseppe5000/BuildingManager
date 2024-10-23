#include "SensorsListPanel.h"
#include "SensorItem.h"

namespace View {

SensorsListPanel::SensorsListPanel(Model::Building& b, QWidget *parent)
    : QWidget(parent), building(b)
{
    layout = new QVBoxLayout(this);
    building.registerObserver(this);
}

void SensorsListPanel::notify(const Model::Building& building) {
    // Clear layout
    QLayoutItem* item;
    while ( ( item = layout->takeAt(0) ) != nullptr ) {
        delete item->widget();
        delete item;
    }

    for (unsigned int i = 0; i < building.getSize(); i++) {
        SensorItem* p = new SensorItem(building.getSensor(i));
        p->setMaximumHeight(100);
        p->setMinimumHeight(100);
        connect(p, &SensorItem::selectSensor, this, &SensorsListPanel::selectSensor);
        connect(p, &SensorItem::editSensor, this, &SensorsListPanel::editSensor);
        connect(p, &SensorItem::deleteSensor, this, &SensorsListPanel::deleteSensor);
        connect(p, &SensorItem::deleteSensor, this, &SensorsListPanel::doDelete);
        layout->addWidget(p);
    }
    layout->addStretch();
}

void SensorsListPanel::doDelete(const Model::Sensor& sensor) {
    building.removeSensor(sensor);
}

void SensorsListPanel::search(const std::string& query) {
    // Clear layout
    QLayoutItem* item;
    while ( ( item = layout->takeAt(0) ) != nullptr ) {
        delete item->widget();
        delete item;
    }

    for (unsigned int i = 0; i < building.getSize(); i++) {
        Model::Sensor& sensor = building.getSensor(i);

        std::string manufactor = sensor.getManufactor();
        std::transform(manufactor.begin(), manufactor.end(), manufactor.begin(), ::tolower);

        std::string model = sensor.getModel();
        std::transform(model.begin(), model.end(), model.begin(), ::tolower);

        if(manufactor.find(query) != std::string::npos || model.find(query) != std::string::npos) {
            SensorItem* p = new SensorItem(sensor);
            p->setMaximumHeight(100);
            p->setMinimumHeight(100);
            connect(p, &SensorItem::selectSensor, this, &SensorsListPanel::selectSensor);
            connect(p, &SensorItem::editSensor, this, &SensorsListPanel::editSensor);
            connect(p, &SensorItem::deleteSensor, this, &SensorsListPanel::deleteSensor);
            connect(p, &SensorItem::deleteSensor, this, &SensorsListPanel::doDelete);
            layout->addWidget(p);
        }
    }
    layout->addStretch();
}

}
