#ifndef _MAINSWITCH_H
#define _MAINSWITCH_H

#include "Devices.h"
#include "SystemDevices.h"

#define MAX_CURRENT 50000 //mA
#define ALARM_CURRENT 40000 //mA

class MainSwitch : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    MainSwitch(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif