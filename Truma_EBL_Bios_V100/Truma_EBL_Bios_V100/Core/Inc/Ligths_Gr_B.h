#ifndef _LIGTHS_GR_B_H
#define _LIGTHS_GR_B_H

#include "Devices.h"
#include "SystemDevices.h"

class LigthsGrB : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    LigthsGrB(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif