/* *******************************************************************************
 *       @file              WaterPump.h
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _WATERPUMP_H
#define _WATERPUMP_H

#include "Devices.h"
#include "SystemDevices.h"

class WaterPump : public Devices, public SystemDevices
{
private:
    uint64_t expirationTime;
    int state;
		bool stateChange;
public:
    WaterPump(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif