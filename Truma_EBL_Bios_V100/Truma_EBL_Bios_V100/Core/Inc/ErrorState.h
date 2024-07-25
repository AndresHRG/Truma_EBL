#ifndef _ERRORSTATE_H
#define _ERRORSTATE_H

#include "Devices.h"

class ErrorState : public Devices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    ErrorState(short _idTopic);

    void setOn();
    void setOff();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif