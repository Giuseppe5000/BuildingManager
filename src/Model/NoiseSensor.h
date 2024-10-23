#ifndef NOISESENSOR_H
#define NOISESENSOR_H

#include "Sensor.h"

namespace Model {

class NoiseSensor: public Sensor
{
public:
    enum Microphone {capacitor, dynamic, tape, crystal};
    NoiseSensor(const std::string&, const std::string&, float, std::pair<double,double>, Microphone);
    Microphone getMicrophone() const;
    void setMicrophone(Microphone);
    std::vector<double> simulation(unsigned int = 15) const override;
    void accept(SensorVisitorInterface&) override;
    void accept(SensorConstVisitorInterface&) const override;

private:
    Microphone microphone;
};

}
#endif // NOISESENSOR_H
