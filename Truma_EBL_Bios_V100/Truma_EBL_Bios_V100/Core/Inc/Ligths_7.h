#ifndef _LIGTHS7_H
#define _LIGTHS7_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths7 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    Ligths7(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif