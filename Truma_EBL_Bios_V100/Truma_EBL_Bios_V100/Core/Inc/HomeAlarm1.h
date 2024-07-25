#ifndef _HOMEALARM1_H
#define _HOMEALARM1_H

#include "Devices.h"
#include "SystemDevices.h"

class HomeAlarm1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    HomeAlarm1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif