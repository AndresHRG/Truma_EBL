#ifndef _DCDCBooster_H
#define _DCDCBooster_H

#include "Devices.h"
#include "SystemDevices.h"

class DCDCBooster : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    DCDCBooster(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif