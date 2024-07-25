#ifndef _INVERTER_H
#define _INVERTER_H

#include "Devices.h"
#include "SystemDevices.h"

#define ID_CONTROL 0x1C
#define ID_INFO    0x1D

class Inverter : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		int noResponse;
		bool stateChange;
		bool aviableLin;
		unsigned char inverter[10];
public:
    Inverter(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif