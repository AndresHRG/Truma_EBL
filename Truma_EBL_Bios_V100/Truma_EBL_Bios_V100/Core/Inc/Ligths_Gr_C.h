#ifndef _LIGTHS_GR_C_H
#define _LIGTHS_GR_C_H

#include "Devices.h"
#include "SystemDevices.h"

class LigthsGrC : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    LigthsGrC(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif