#ifndef _LIGTHS_1_H
#define _LIGTHS_1_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    Ligths1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif