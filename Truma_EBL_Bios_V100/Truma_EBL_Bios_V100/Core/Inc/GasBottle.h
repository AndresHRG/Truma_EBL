#ifndef _GASBOTTLE_H
#define _GASBOTTLE_H

#include "Devices.h"
#include "SystemDevices.h"

class GasBottle : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    GasBottle(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif