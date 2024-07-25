#ifndef _AESFRIDGE_H
#define _AESFRIDGE_H

#include "Devices.h"
#include "SystemDevices.h"

class AESFridge : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    AESFridge(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif