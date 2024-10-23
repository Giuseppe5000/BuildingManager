#include "SensorInfoVisitor.h"
#include "Model/BrightnessSensor.h"
#include "Model/NoiseSensor.h"
#include "Model/TemperatureSensor.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIcon>
#include <sstream>
#include <iomanip>

namespace View {

QWidget* SensorInfoVisitor::getWidget() const {
    return widget;
}

void SensorInfoVisitor::visitBrightnessSensor(const Model::BrightnessSensor& s) {
    widget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout(widget);

    QLabel* icon = new QLabel;
    icon->setPixmap(QPixmap(":/assets/icons/brightness.svg"));
    icon->setMaximumHeight(30);
    icon->setMaximumWidth(30);
    icon->setScaledContents(true);
    layout->addWidget(icon);

    QVBoxLayout* infoLayout = new QVBoxLayout;
    std::string name = "Manufactor: " + s.getManufactor() + ", Model: " + s.getModel();
    infoLayout->addWidget(new QLabel(QString::fromStdString(name)));

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << s.getPrecision();
    std::string infos = "Precision: " + stream.str() + "%, Visual Field: " + std::to_string(s.getVisualField()) + "°";
    infoLayout->addWidget(new QLabel(QString::fromStdString(infos)));

    layout->addLayout(infoLayout);
}

void SensorInfoVisitor::visitNoiseSensor(const Model::NoiseSensor& s) {
    widget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout(widget);

    QLabel* icon = new QLabel;
    icon->setPixmap(QPixmap(":/assets/icons/noise.svg"));
    icon->setMaximumHeight(30);
    icon->setMaximumWidth(30);
    icon->setScaledContents(true);
    layout->addWidget(icon);

    QVBoxLayout* infoLayout = new QVBoxLayout;
    std::string name = "Manufactor: " + s.getManufactor() + ", Model: " + s.getModel();
    infoLayout->addWidget(new QLabel(QString::fromStdString(name)));

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << s.getPrecision();
    std::string infos = "Precision: " + stream.str() + "%, Microphone: ";
    switch(s.getMicrophone()) {
    case Model::NoiseSensor::Microphone::capacitor:
        infos += "Capacitor";
        break;
    case Model::NoiseSensor::Microphone::dynamic:
        infos += "Dynamic";
        break;
    case Model::NoiseSensor::Microphone::tape:
        infos += "Tape";
        break;
    case Model::NoiseSensor::Microphone::crystal:
        infos += "Crystal";
        break;
    }
    infoLayout->addWidget(new QLabel(QString::fromStdString(infos)));

    layout->addLayout(infoLayout);
}

void SensorInfoVisitor::visitTemperatureSensor(const Model::TemperatureSensor& s) {
    widget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout(widget);

    QLabel* icon = new QLabel;
    icon->setPixmap(QPixmap(":/assets/icons/temperature.svg"));
    icon->setMaximumHeight(30);
    icon->setMaximumWidth(30);
    icon->setScaledContents(true);
    layout->addWidget(icon);

    QVBoxLayout* infoLayout = new QVBoxLayout;
    std::string name = "Manufactor: " + s.getManufactor() + ", Model: " + s.getModel();
    infoLayout->addWidget(new QLabel(QString::fromStdString(name)));

    std::stringstream precisionStream;
    precisionStream << std::fixed << std::setprecision(2) << s.getPrecision();
    std::stringstream resistanceStream;
    resistanceStream << std::fixed << std::setprecision(2) << s.getResistance();
    std::string infos = "Precision: " + precisionStream.str() + "%, Resistance: " + resistanceStream.str() + " Ω";
    infoLayout->addWidget(new QLabel(QString::fromStdString(infos)));

    layout->addLayout(infoLayout);
}

}
