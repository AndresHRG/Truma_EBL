#ifndef _WATERPUMP_H
#define _WATERPUMP_H

#include "Devices.h"
#include "SystemDevices.h"

class WaterPump : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    WaterPump(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif