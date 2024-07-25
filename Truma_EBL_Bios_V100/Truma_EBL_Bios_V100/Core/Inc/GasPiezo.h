#ifndef _GASPIEZO_H
#define _GASPIEZO_H

#include "Devices.h"
#include "SystemDevices.h"

class GasPiezo : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    GasPiezo(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif