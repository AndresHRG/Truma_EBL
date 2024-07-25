#ifndef _EXTERNAL_LIGTHS2_H
#define _EXTERNAL_LIGTHS2_H

#include "Devices.h"
#include "SystemDevices.h"

class ExternalLigths2 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    ExternalLigths2(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif