#ifndef _IBSSENSOR2_H
#define _IBSSENSOR2_H

#include "Devices.h"
#include "SystemDevices.h"

class IBSSensor2 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    IBSSensor2(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif