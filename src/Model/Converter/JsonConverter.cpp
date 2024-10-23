#include "JsonConverter.h"
#include "SensorJsonVisitor.h"
#include "Model/BrightnessSensor.h"
#include "Model/NoiseSensor.h"
#include "Model/TemperatureSensor.h"
#include <QJsonArray>

namespace Model::Converter {

QJsonDocument JsonConverter::convert(const Building& building) {
    QJsonArray sensorsJson;

    for (unsigned int i = 0; i < building.getSize(); i++) {
        SensorJsonVisitor visitor;
        building.getSensor(i).accept(visitor);
        sensorsJson.push_back(visitor.getJson());
    }

    return QJsonDocument(sensorsJson);
}

void JsonConverter::parse(Building& building, const QJsonDocument& jsonDoc) {
    QJsonArray json = jsonDoc.array();

    for(const QJsonValue& sensor : json) {
        QJsonObject sensorObj = sensor.toObject();

        std::string manufactor = sensorObj["manufactor"].toString().toStdString();
        std::string model = sensorObj["model"].toString().toStdString();
        float precision = sensorObj["precision"].toDouble();

        std::pair<double, double> range(0.0, 100.0);
        if (sensorObj.contains("range") && sensorObj["range"].isArray() && !sensorObj["range"].toArray().isEmpty())
            range = std::make_pair<double,double>(sensorObj["range"].toArray()[0].toDouble(), sensorObj["range"].toArray()[1].toDouble());

        if (sensorObj["type"].toString() == "brightness") {
            unsigned short visualField = sensorObj["visualField"].toInt();
            building.addSensor(new BrightnessSensor(manufactor, model, precision, range, visualField));
        }
        else if (sensorObj["type"].toString() == "noise") {
            NoiseSensor::Microphone microphone = static_cast<NoiseSensor::Microphone>(sensorObj["microphone"].toInt());
            building.addSensor(new NoiseSensor(manufactor, model, precision, range, microphone));
        }
        else if (sensorObj["type"].toString() == "temperature") {
            double resistance = sensorObj["resistance"].toDouble();
            building.addSensor(new TemperatureSensor(manufactor, model, precision, range, resistance));
        }

    }
}

}
