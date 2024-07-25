#ifndef _AUXOUTPUT_H
#define _AUXOUTPUT_H

#include "Devices.h"
#include "SystemDevices.h"

class AuxOutPut : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    AuxOutPut(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif