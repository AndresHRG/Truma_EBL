/* *******************************************************************************
 *       @file              Multimedia.h
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _MULTIMEDIA_H
#define _MULTIMEDIA_H

#include "Devices.h"
#include "SystemDevices.h"

class Multimedia : public Devices, public SystemDevices
{
private:
    uint64_t expirationTime;
    int state;
public:
    Multimedia(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif