#ifndef _LIGTHSGRE_H
#define _LIGTHSGRE_H

#include "Devices.h"
#include "SystemDevices.h"

class LigthsGrE : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    LigthsGrE(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif