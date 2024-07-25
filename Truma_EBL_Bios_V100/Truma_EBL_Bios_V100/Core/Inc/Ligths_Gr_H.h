#ifndef _LIGTHSGRH_H
#define _LIGTHSGRH_H

#include "Devices.h"
#include "SystemDevices.h"

class LigthsGrH : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    LigthsGrH(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif