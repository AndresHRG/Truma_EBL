#ifndef _FAN_H
#define _FAN_H

#include "Devices.h"
#include "SystemDevices.h"

class Fan : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    Fan(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif