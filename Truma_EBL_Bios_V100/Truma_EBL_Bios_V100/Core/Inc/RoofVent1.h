#ifndef _ROOFVENT1_H
#define _ROOFVENT1_H

#include "Devices.h"
#include "SystemDevices.h"

class RoofVent1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    RoofVent1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif