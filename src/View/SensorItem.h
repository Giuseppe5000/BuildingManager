#ifndef SENSORITEM_H
#define SENSORITEM_H

#include "Model/Sensor.h"
#include <QWidget>
#include <QPushButton>

namespace View {

class SensorItem : public QWidget
{
    Q_OBJECT
private:
    Model::Sensor& sensor;
    QPushButton* sensorBtn;
    QPushButton* editBtn;
    QPushButton* deleteBtn;
public:
    explicit SensorItem(Model::Sensor&, QWidget *parent = nullptr);
public slots:
    void editClicked();
    void editRefresh(const Model::Sensor&);
signals:
    void selectSensor(const Model::Sensor&);
    void editSensor(const Model::Sensor&);
    void deleteSensor(const Model::Sensor&);
};

}
#endif // SENSORITEM_H
