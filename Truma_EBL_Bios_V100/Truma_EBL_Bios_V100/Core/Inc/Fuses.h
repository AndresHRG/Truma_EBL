/* *******************************************************************************
 *       @file              Fuses.h
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _FUSES_H
#define _FUSES_H

#include "Devices.h"
#include "SystemDevices.h"

#define FUSE_OK 0
#define FUSE_KO 1

class Fuses : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    Fuses(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif