#ifndef SENSOR_H
#define SENSOR_H

#include "SensorVisitorInterface.h"
#include "SensorConstVisitorInterface.h"
#include <string>
#include <vector>
#include <utility>

namespace Model {

class Sensor
{
private:
    std::string manufactor;
    std::string model;
    float precision;
    std::pair<double, double> range;
public:
    Sensor(const std::string&, const std::string&, float, std::pair<double,double>);
    virtual ~Sensor() = default;
    std::string getManufactor() const;
    std::string getModel() const;
    float getPrecision() const;
    std::pair<double,double> getRange() const;
    void setManufactor(const std::string&);
    void setModel(const std::string&);
    void setPrecision(float);
    void setRange(std::pair<double,double>);
    virtual std::vector<double> simulation(unsigned int=15) const = 0;
    virtual void accept(SensorVisitorInterface&) = 0;
    virtual void accept(SensorConstVisitorInterface&) const = 0;
};

}
#endif // SENSOR_H
