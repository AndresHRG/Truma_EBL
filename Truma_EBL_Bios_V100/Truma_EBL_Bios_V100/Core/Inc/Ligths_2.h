#ifndef _LIGTHS_2_H
#define _LIGTHS_2_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths2 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    Ligths2(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif