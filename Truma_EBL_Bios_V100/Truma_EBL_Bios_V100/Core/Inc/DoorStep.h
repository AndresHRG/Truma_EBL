#ifndef _DOORSTEP_H
#define _DOORSTEP_H

#include "Devices.h"
#include "SystemDevices.h"

class DoorStep : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    DoorStep(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif