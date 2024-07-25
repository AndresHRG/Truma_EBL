#ifndef _LIGTHS_GR_D_H
#define _LIGTHS_GR_D_H

#include "Devices.h"
#include "SystemDevices.h"

class LigthsGrD : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    LigthsGrD(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif