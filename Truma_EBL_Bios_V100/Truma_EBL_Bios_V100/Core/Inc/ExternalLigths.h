#ifndef _EXTERNALIGTHS_H
#define _EXTERNALIGTHS_H

#include "Devices.h"
#include "SystemDevices.h"

class ExternalLigths : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    ExternalLigths(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif