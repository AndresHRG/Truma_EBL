/* *******************************************************************************
 *       @file              FreshWater_1.h
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _FRESHWATER1_H
#define _FRESHWATER1_H

#include "Devices.h"
#include "SystemDevices.h"

class FreshWater1 : public Devices, public SystemDevices
{
private:
    uint64_t expirationTime;
		uint64_t powerTime;
    int state;
		float levelFW;
		int counterFW;
public:
    FreshWater1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif