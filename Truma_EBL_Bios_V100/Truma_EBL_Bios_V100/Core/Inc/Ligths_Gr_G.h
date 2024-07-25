#ifndef _LIGTHGRG_H
#define _LIGTHGRG_H

#include "Devices.h"
#include "SystemDevices.h"

class LigthsGrG : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    LigthsGrG(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif