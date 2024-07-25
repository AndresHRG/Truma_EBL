#ifndef _HEATER_H
#define _HEATER_H

#include "Devices.h"
#include "SystemDevices.h"

class Heater : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
		unsigned char boiler[10];
		unsigned char heater[10];
		unsigned char airCond[10];
public:
    Heater(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif