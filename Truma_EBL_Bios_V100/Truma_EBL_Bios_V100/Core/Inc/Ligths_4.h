#ifndef _LIGTHS_4_H
#define _LIGTHS_4_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths4 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    Ligths4(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif