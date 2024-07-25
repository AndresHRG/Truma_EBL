#ifndef _DRAINVALVE_H
#define _DRAINVALVE_H

#include "Devices.h"
#include "SystemDevices.h"

class DrainValve : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    DrainValve(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif