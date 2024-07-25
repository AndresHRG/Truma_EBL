#ifndef _TPMSSENSOR_H
#define _TPMSSENSOR_H

#include "Devices.h"
#include "SystemDevices.h"

class TPMSSensor : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    TPMSSensor(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif