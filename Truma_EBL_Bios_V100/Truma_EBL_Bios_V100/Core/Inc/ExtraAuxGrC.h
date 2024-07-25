#ifndef _EXTRAAUXGRC_H
#define _EXTRAAUXGRC_H

#include "Devices.h"
#include "SystemDevices.h"

class ExtraAuxGrC : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    ExtraAuxGrC(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif