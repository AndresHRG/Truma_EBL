/* *******************************************************************************
 *       @file              EmptyingValve.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _EMPTYINGVALVE_H
#define _EMPTYINGVALVE_H

#include "Devices.h"
#include "SystemDevices.h"

class EmptyingValve : public Devices, public SystemDevices
{
private:
    uint64_t expirationTime;
    int state;
		bool stateChange;
public:
    EmptyingValve(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif