#ifndef _LIGTHS8_H
#define _LIGTHS8_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths8 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    Ligths8(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif