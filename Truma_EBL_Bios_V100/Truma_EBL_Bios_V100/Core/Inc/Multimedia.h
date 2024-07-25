#ifndef _MULTIMEDIA_H
#define _MULTIMEDIA_H

#include "Devices.h"
#include "SystemDevices.h"

class Multimedia : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    Multimedia(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif