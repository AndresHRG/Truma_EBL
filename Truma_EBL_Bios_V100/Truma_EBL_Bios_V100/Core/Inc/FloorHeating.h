/* *******************************************************************************
 *       @file              FloorHeating.cpp
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _FLOORHEATING_H
#define _FLOORHEATING_H

#include "Devices.h"
#include "SystemDevices.h"

class FloorHeating : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    FloorHeating(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif