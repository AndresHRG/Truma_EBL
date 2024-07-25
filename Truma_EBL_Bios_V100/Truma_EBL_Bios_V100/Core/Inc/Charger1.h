#ifndef _CHARGER1_H
#define _CHARGER1_H

#include "Devices.h"
#include "SystemDevices.h"

class Charger1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    Charger1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
    
};

#endif