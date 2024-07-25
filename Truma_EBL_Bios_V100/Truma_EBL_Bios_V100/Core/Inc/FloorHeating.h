#ifndef _FLOORHEATING_H
#define _FLOORHEATING_H

#include "Devices.h"
#include "SystemDevices.h"

class FloorHeating : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    FloorHeating(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif