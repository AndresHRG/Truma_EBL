#ifndef _EXTRAAUXGRH_H
#define _EXTRAAUXGRH_H

#include "Devices.h"
#include "SystemDevices.h"

class ExtraAuxGrH : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    ExtraAuxGrH(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif
