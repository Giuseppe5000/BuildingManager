#include "SensorsPanel.h"
#include "Dialogs/AddSensorDialog.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>

namespace View {

SensorsPanel::SensorsPanel(Model::Building& b, QWidget *parent)
    : QWidget(parent), building(b)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    search_panel = new SearchPanel(building);
    layout->addWidget(search_panel);

    QScrollArea* scroll = new QScrollArea;
    layout->addWidget(scroll);

    sensors_list_panel = new SensorsListPanel(building);
    sensors_list_panel->setObjectName("SensorsListPanel");
    scroll->setWidget(sensors_list_panel);
    scroll->setWidgetResizable(true);
    scroll->setMinimumWidth(270);

    addSensor = new QPushButton("Add a sensor");
    addSensor->setObjectName("addSensor");
    layout->addWidget(addSensor);

    connect(sensors_list_panel, &SensorsListPanel::selectSensor, this, &SensorsPanel::selectSensor);
    connect(sensors_list_panel, &SensorsListPanel::editSensor, this, &SensorsPanel::editSensor);
    connect(sensors_list_panel, &SensorsListPanel::deleteSensor, this, &SensorsPanel::deleteSensor);
    connect(search_panel, &SearchPanel::search, sensors_list_panel, &SensorsListPanel::search);
    connect(addSensor, &QPushButton::clicked, this, &SensorsPanel::showAddDialog);
}

void SensorsPanel::showAddDialog() {
    new Dialog::AddSensorDialog(building, this);
}

}
