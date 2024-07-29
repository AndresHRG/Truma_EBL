#ifndef _GRAYWATER1_H
#define _GRAYWATER1_H

#include "Devices.h"
#include "SystemDevices.h"

class GrayWater1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
		unsigned long long powerTime;
    int state;
		float levelGW;
		int counterGW;
public:
    GrayWater1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif