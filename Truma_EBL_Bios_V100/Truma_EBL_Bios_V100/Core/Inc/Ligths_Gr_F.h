#ifndef _LIGTHSGRF_H
#define _LIGTHSGRF_H

#include "Devices.h"
#include "SystemDevices.h"

class LigthsGrF : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    LigthsGrF(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif