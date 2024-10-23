#ifndef SENSORSLISTPANEL_H
#define SENSORSLISTPANEL_H

#include "Model/Building.h"
#include "Model/BuildingObserverInterface.h"
#include <QWidget>
#include <QVBoxLayout>

namespace View {

class SensorsListPanel : public QWidget, public Model::BuildingObserverInterface
{
    Q_OBJECT
private:
    Model::Building& building;
    QVBoxLayout* layout;
public:
    explicit SensorsListPanel(Model::Building&, QWidget *parent = nullptr);
    void notify(const Model::Building&) override;
public slots:
    void doDelete(const Model::Sensor&);
    void search(const std::string&);
signals:
    void selectSensor(const Model::Sensor&);
    void editSensor(const Model::Sensor&);
    void deleteSensor(const Model::Sensor&);
};

}
#endif // SENSORSLISTPANEL_H
