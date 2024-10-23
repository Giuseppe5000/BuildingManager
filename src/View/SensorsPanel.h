#ifndef SENSORSPANEL_H
#define SENSORSPANEL_H

#include "Model/Building.h"
#include "SearchPanel.h"
#include "SensorsListPanel.h"
#include <QWidget>
#include <QPushButton>

namespace View {

class SensorsPanel : public QWidget
{
    Q_OBJECT
private:
    Model::Building& building;
    SearchPanel* search_panel;
    SensorsListPanel* sensors_list_panel;
    QPushButton* addSensor;
public:
    explicit SensorsPanel(Model::Building&, QWidget *parent = nullptr);
public slots:
    void showAddDialog();
signals:
    void selectSensor(const Model::Sensor&);
    void editSensor(const Model::Sensor&);
    void deleteSensor(const Model::Sensor&);
};

}
#endif // SENSORSPANEL_H
