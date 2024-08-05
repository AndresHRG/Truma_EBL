/* *******************************************************************************
 *       @file              Fridge.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _FRIDGE_H
#define _FRIDGE_H

#include "Devices.h"
#include "SystemDevices.h"

class Fridge : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
		bool stateChange;
public:
    Fridge(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif