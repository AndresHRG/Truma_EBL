#ifndef _INTERNALIGTHS_H
#define _INTERNALIGTHS_H

#include "Devices.h"
#include "SystemDevices.h"

class InternalLigths : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    InternalLigths(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
		void modeOff();
    int getTopicState();
};

#endif