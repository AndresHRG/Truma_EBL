#ifndef _LIGTHS_3_H
#define _LIGTHS_3_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths3 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    Ligths3(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif