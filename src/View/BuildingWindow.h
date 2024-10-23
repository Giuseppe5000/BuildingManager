#ifndef BUILDINGWINDOW_H
#define BUILDINGWINDOW_H

#include "SensorsPanel.h"
#include "SimulationPanel.h"
#include "BuildingMenuBar.h"
#include "Model/Building.h"
#include <QWidget>
#include <QDropEvent>
#include <QDragEnterEvent>

namespace View {

class BuildingWindow : public QWidget
{
    Q_OBJECT
private:
    Model::Building& building;
    BuildingMenuBar* menuBar;
    SensorsPanel* sensors_panel;
    SimulationPanel* simulation_panel;
public:
    explicit BuildingWindow(Model::Building&, QWidget *parent = nullptr);
    void dropEvent(QDropEvent*);
    void dragEnterEvent(QDragEnterEvent*);
};

}
#endif // BUILDINGWINDOW_H
