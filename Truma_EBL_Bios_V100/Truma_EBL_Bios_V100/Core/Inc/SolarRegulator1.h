#ifndef _SOLARREGULATOR1_H
#define _SOLARREGULATOR1_H

#include "Devices.h"
#include "SystemDevices.h"
#include "LinClients.h"

class SolarRegulator1 : public Devices, public SystemDevices, public LinClients
{
private:
    unsigned long long expirationTime;
    int state;
		int noResponse;
		bool stateChange;
		bool aviableLin;
public:
    SolarRegulator1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
		void processInfoFrame(uint8_t* frame);
};

#endif