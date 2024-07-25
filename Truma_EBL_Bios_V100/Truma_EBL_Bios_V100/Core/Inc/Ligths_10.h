#ifndef _LIGTHS10_H
#define _LIGTHS10_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths10 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    Ligths10(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
		void nigthModeOff();
    int getTopicState();
};

#endif