#ifndef _GASALARM1_H
#define _GASALARM1_H

#include "Devices.h"
#include "SystemDevices.h"

class GasAlarm1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    GasAlarm1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif