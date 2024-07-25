#ifndef _AUXGRD_H
#define _AUXGRD_H

#include "Devices.h"
#include "SystemDevices.h"

class AuxGrD : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    AuxGrD(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif