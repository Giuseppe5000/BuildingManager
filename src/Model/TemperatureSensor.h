#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.h"

namespace Model {

class TemperatureSensor: public Sensor
{
private:
    double resistance;
public:
    TemperatureSensor(const std::string&, const std::string&, float, std::pair<double,double>, double);
    double getResistance() const;
    void setResistance(double);
    std::vector<double> simulation(unsigned int = 15) const override;
    void accept(SensorVisitorInterface&) override;
    void accept(SensorConstVisitorInterface&) const override;
};

}
#endif // TEMPERATURESENSOR_H
