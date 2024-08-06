/* *******************************************************************************
 *       @file              LeisureBattery1.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _LEISUREBATTERY1_H
#define _LEISUREBATTERY1_H

#include "Devices.h"
#include "SystemDevices.h"
#include "LinClients.h"

class LeisureBattery1 : public Devices, public SystemDevices, public LinClients 
{
private:
    uint64_t expirationTime;
public:
    LeisureBattery1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
		void processInfoFrame(uint8_t* frame);

		int state;
		float mAmps;
		int timeRemaining;
		int soc;
		int volts;
};

#endif