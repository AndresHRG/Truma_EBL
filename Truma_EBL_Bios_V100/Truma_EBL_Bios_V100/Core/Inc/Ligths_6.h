#ifndef _LIGTHS6_H
#define _LIGTHS6_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths6 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    Ligths6(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif