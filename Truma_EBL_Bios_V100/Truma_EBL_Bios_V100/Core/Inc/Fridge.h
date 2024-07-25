#ifndef _FRIDGE_H
#define _FRIDGE_H

#include "Devices.h"
#include "SystemDevices.h"

class Fridge : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    Fridge(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif