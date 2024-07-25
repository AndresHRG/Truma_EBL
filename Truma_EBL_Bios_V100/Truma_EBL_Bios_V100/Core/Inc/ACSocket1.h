#ifndef _ACSOCKET1_H
#define _ACSOCKET1_H

#include "Devices.h"
#include "SystemDevices.h"

class ACSocket1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    ACSocket1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
		int getTopicState();
};

#endif