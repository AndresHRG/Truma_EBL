#ifndef _SAT_H
#define _SAT_H

#include "Devices.h"
#include "SystemDevices.h"

class Sat : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    Sat(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif