#ifndef _LIGTHS11_H
#define _LIGTHS11_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths11 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    Ligths11(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif