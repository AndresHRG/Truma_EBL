#ifndef _LIGTHS9_H
#define _LIGTHS9_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths9 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    Ligths9(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif