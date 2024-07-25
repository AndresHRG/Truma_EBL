#ifndef _LIGTHS_5_H
#define _LIGTHS_5_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths5 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    Ligths5(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif