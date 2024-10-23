#ifndef BRIGHTNESSSENSOR_H
#define BRIGHTNESSSENSOR_H

#include "Sensor.h"

namespace Model {

class BrightnessSensor: public Sensor
{
private:
    unsigned short visualField;
public:
    BrightnessSensor(const std::string&, const std::string&, float, std::pair<double,double>, unsigned short);
    unsigned short getVisualField() const;
    void setVisualField(unsigned short);
    std::vector<double> simulation(unsigned int=15) const override;
    void accept(SensorVisitorInterface&) override;
    void accept(SensorConstVisitorInterface&) const override;
};

}
#endif // BRIGHTNESSSENSOR_H
