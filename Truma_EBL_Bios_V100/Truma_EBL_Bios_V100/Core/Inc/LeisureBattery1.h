#ifndef _LEISUREBATTERY1_H
#define _LEISUREBATTERY1_H

#include "Devices.h"
#include "SystemDevices.h"
#include "LinClients.h"

class LeisureBattery1 : public Devices, public SystemDevices, public LinClients 
{
private:
    unsigned long long expirationTime;
public:
    LeisureBattery1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
		void processInfoFrame(uint8_t* frame);

		int state;
		int mAmps;
		int timeRemaining;
		int soc;
		int volts;
};

#endif