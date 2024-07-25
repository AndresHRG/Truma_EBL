#ifndef _EMPTYINGVALVE_H
#define _EMPTYINGVALVE_H

#include "Devices.h"
#include "SystemDevices.h"

class EmptyingValve : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    EmptyingValve(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif