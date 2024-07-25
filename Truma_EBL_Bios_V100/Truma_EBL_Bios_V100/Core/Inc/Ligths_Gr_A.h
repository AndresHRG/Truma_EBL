#ifndef _LIGTHS_GR_A_H
#define _LIGTHS_GR_A_H

#include "Devices.h"
#include "SystemDevices.h"

class LigthsGrA : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    LigthsGrA(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif