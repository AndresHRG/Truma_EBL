#ifndef _FRESHWATER1_H
#define _FRESHWATER1_H

#include "Devices.h"
#include "SystemDevices.h"

class FreshWater1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
		unsigned long long powerTime;
    int state;
		float levelFW;
		int counterFW;
public:
    FreshWater1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif