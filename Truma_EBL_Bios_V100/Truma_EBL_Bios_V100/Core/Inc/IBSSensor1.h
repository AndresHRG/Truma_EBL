#ifndef _IBSSENSOR1_H
#define _IBSSENSOR1_H

#include "Devices.h"
#include "SystemDevices.h"

class IBSSensor1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    IBSSensor1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif