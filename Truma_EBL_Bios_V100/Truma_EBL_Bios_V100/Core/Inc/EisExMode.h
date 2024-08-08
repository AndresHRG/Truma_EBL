#ifndef _EISEXMODE_H
#define _EISEXMODE_H

#include "Devices.h"
#include "SystemDevices.h"

class EisExMode : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    EisExMode(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif