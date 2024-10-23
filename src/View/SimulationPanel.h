#ifndef SIMULATIONPANEL_H
#define SIMULATIONPANEL_H

#include "Model/Sensor.h"
#include <QWidget>
#include <QChart>
#include <QVBoxLayout>
#include <QSpinBox>

namespace View {

class SimulationPanel : public QWidget
{
    Q_OBJECT
private:
    const Model::Sensor* sensor;
    QChart* simulationChart;
    QWidget* info;
    QSpinBox* samples;
    QVBoxLayout* layout;
public:
    explicit SimulationPanel(const Model::Sensor* = nullptr, QWidget *parent = nullptr);
public slots:
    void selectSensor(const Model::Sensor&);
    void deleteSensor(const Model::Sensor&);
    void editSensor(const Model::Sensor&);
    void fileChanged();
    void simulation();
};

}
#endif // SIMULATIONPANEL_H
