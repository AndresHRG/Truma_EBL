#ifndef _DPLUS_OUTPUTS_H
#define _DPLUS_OUTPUTS_H

#include "Devices.h"
#include "SystemDevices.h"

class DPlusOutputs : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    DPlusOutputs(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif