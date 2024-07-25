#ifndef _LIGTHS12_H
#define _LIGTHS12_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths12 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    Ligths12(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif