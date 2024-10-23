#include "BuildingWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMimeData>
#include <QFileInfo>

namespace View {

BuildingWindow::BuildingWindow(Model::Building& b, QWidget *parent)
    : QWidget(parent), building(b)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    
    menuBar = new BuildingMenuBar(building);
    mainLayout->addWidget(menuBar);

    QHBoxLayout* screenLayout = new QHBoxLayout;

    sensors_panel = new SensorsPanel(building);
    screenLayout->addWidget(sensors_panel);
    screenLayout->setStretch(0, 3);

    simulation_panel = new SimulationPanel;
    screenLayout->addWidget(simulation_panel);
    screenLayout->setStretch(1, 7);

    mainLayout->addLayout(screenLayout);

    setAcceptDrops(true);

    connect(sensors_panel, &SensorsPanel::selectSensor, simulation_panel, &SimulationPanel::selectSensor);
    connect(sensors_panel, &SensorsPanel::editSensor, simulation_panel, &SimulationPanel::editSensor);
    connect(sensors_panel, &SensorsPanel::deleteSensor, simulation_panel, &SimulationPanel::deleteSensor);
    connect(menuBar, &BuildingMenuBar::fileChanged, simulation_panel, &SimulationPanel::fileChanged);
}

void BuildingWindow::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasUrls() && QFileInfo(event->mimeData()->urls()[0].toLocalFile()).completeSuffix() == "json")
        event->acceptProposedAction();
}

void BuildingWindow::dropEvent(QDropEvent *event) {
    menuBar->openFile(event->mimeData()->urls()[0].toLocalFile());
    event->acceptProposedAction();
}

}
