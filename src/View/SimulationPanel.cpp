#include "SimulationPanel.h"
#include "Visitors/SensorInfoVisitor.h"
#include <QChartView>
#include <QLineSeries>
#include <QPushButton>
#include <QLabel>
#include <QValueAxis>

namespace View {

SimulationPanel::SimulationPanel(const Model::Sensor* s, QWidget *parent)
    : QWidget(parent), sensor(s)
{
    layout = new QVBoxLayout(this);

    info = new QLabel("Select a sensor from the list");
    layout->addWidget(info);

    simulationChart = new QChart;
    simulationChart->legend()->hide();
    simulationChart->setTitle("Simulation");
    simulationChart->setAnimationOptions(QChart::SeriesAnimations);
    simulationChart->setAnimationDuration(1000);
    simulationChart->setTheme(QChart::ChartThemeDark);

    QChartView* chartView = new QChartView(simulationChart);

    layout->addWidget(chartView);

    QHBoxLayout* simulationCountLayout = new QHBoxLayout;
    simulationCountLayout->addWidget(new QLabel("Samples"));
    samples = new QSpinBox;
    samples->setValue(15);
    simulationCountLayout->addWidget(samples);
    QPushButton* simulation = new QPushButton("Simulation");
    simulation->setObjectName("simulation");
    simulationCountLayout->addWidget(simulation);

    simulationCountLayout->setStretch(0, 0);
    simulationCountLayout->setStretch(1, 0);
    simulationCountLayout->setStretch(2, 1);

    layout->addLayout(simulationCountLayout);

    connect(simulation, &QPushButton::clicked, this, &SimulationPanel::simulation);
}

void SimulationPanel::simulation() {
    if(sensor != nullptr) {

        simulationChart->removeAllSeries();

        QLineSeries* series = new QLineSeries;

        QList<QPointF> f;
        std::vector<double> sim = sensor->simulation(samples->value());

        unsigned int counter = 0;
        for (auto s : sim) {
            f.append(QPointF(counter,s));
            counter++;
         }

        series->append(f);

        QPen pen(Qt::cyan);
        pen.setWidth(3);
        series->setPen(pen);
        simulationChart->addSeries(series);
        simulationChart->createDefaultAxes();
        simulationChart->axes(Qt::Vertical).at(0)->setRange(sensor->getRange().first, sensor->getRange().second);
    }
}

void SimulationPanel::selectSensor(const Model::Sensor& s) {
    sensor = &s;
    SensorInfoVisitor visitor;
    sensor->accept(visitor);
    layout->removeWidget(info);
    delete info;
    info = visitor.getWidget();
    layout->insertWidget(0, info);
    simulationChart->removeAllSeries();

    auto axes = simulationChart->axes();
    for (auto axe : axes) {
        delete axe;
    }

    samples->setValue(15);
}

void SimulationPanel::deleteSensor(const Model::Sensor& s) {
    if (sensor == &s) {
        sensor = nullptr;
        layout->removeWidget(info);
        delete info;
        info = new QLabel("Select a sensor from the list");
        layout->insertWidget(0, info);
        simulationChart->removeAllSeries();

        auto axes = simulationChart->axes();
        for (auto axe : axes) {
            delete axe;
        }

        samples->setValue(15);
    }
}

void SimulationPanel::editSensor(const Model::Sensor& s) {
    if (sensor == &s) {
        SensorInfoVisitor visitor;
        sensor->accept(visitor);
        layout->removeWidget(info);
        delete info;
        info = visitor.getWidget();
        layout->insertWidget(0, info);
        simulationChart->removeAllSeries();

        auto axes = simulationChart->axes();
        for (auto axe : axes) {
            delete axe;
        }

        samples->setValue(15);
    }
}

void SimulationPanel::fileChanged() {
    sensor = nullptr;
    layout->removeWidget(info);
    delete info;
    info = new QLabel("Select a sensor from the list");
    layout->insertWidget(0, info);
    simulationChart->removeAllSeries();

    auto axes = simulationChart->axes();
    for (auto axe : axes) {
        delete axe;
    }

    samples->setValue(15);
}

}
