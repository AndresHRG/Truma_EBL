#ifndef _IDENTITYCHECK_H
#define _IDENTITYCHECK_H

#include "Devices.h"

class IdentityCheck : public Devices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    IdentityCheck(short _idTopic);

    void setOn();
    void setOff();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif