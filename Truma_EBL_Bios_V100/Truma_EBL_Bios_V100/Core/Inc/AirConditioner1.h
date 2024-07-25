#ifndef _AIRCONDITIONER1_H
#define _AIRCONDITIONER1_H

#include "Devices.h"
#include "SystemDevices.h"

class AirConditioner1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
		unsigned char boiler[10];
		unsigned char heater[10];
		unsigned char airCond[10];
public:
    AirConditioner1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif