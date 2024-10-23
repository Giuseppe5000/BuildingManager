#include "SensorJsonVisitor.h"
#include "Model/BrightnessSensor.h"
#include "Model/NoiseSensor.h"
#include "Model/TemperatureSensor.h"
#include <QJsonArray>

namespace Model::Converter {

QJsonObject SensorJsonVisitor::getJson() const {
    return json;
}

void SensorJsonVisitor::visitBrightnessSensor(const BrightnessSensor& s) {
    json.insert("manufactor", QString::fromStdString(s.getManufactor()));
    json.insert("model",QString::fromStdString(s.getModel()));
    json.insert("precision", s.getPrecision());
    QJsonArray range;
    range.push_back(s.getRange().first);
    range.push_back(s.getRange().second);
    json.insert("range", range);
    json.insert("visualField", s.getVisualField());
    json.insert("type", "brightness");
}

void SensorJsonVisitor::visitNoiseSensor(const NoiseSensor& s) {
    json.insert("manufactor", QString::fromStdString(s.getManufactor()));
    json.insert("model",QString::fromStdString(s.getModel()));
    json.insert("precision", s.getPrecision());
    QJsonArray range;
    range.push_back(s.getRange().first);
    range.push_back(s.getRange().second);
    json.insert("range", range);
    json.insert("microphone", s.getMicrophone());
    json.insert("type", "noise");
}

void SensorJsonVisitor::visitTemperatureSensor(const TemperatureSensor& s) {
    json.insert("manufactor", QString::fromStdString(s.getManufactor()));
    json.insert("model",QString::fromStdString(s.getModel()));
    json.insert("precision", s.getPrecision());
    QJsonArray range;
    range.push_back(s.getRange().first);
    range.push_back(s.getRange().second);
    json.insert("range", range);
    json.insert("resistance", s.getResistance());
    json.insert("type", "temperature");
}

}
