#include "MainWindow.h"
#include "BuildingWindow.h"

namespace View {

MainWindow::MainWindow(Model::Building& building, QWidget *parent)
    : QMainWindow(parent)
{
    BuildingWindow* building_window = new BuildingWindow(building);
    setCentralWidget(building_window);
}

}
