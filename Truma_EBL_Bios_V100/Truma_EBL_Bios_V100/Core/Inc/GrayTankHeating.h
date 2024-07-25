#ifndef _GRAYTANKHEATING_H
#define _GRAYTANKHEATING_H

#include "Devices.h"
#include "SystemDevices.h"

class GrayTankHeating : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    GrayTankHeating(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif
