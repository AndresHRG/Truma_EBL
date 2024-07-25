#ifndef _ENERGYSPLITER_H
#define _ENERGYSPLITER_H

#include "Devices.h"
#include "SystemDevices.h"

class EnergySpliter : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    EnergySpliter(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif