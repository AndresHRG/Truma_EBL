/* *******************************************************************************
 *       @file              SolarRegulator1.h
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _SOLARREGULATOR1_H
#define _SOLARREGULATOR1_H

#include "Devices.h"
#include "SystemDevices.h"
#include "LinClients.h"

class SolarRegulator1 : public Devices, public SystemDevices, public LinClients
{
private:
    uint64_t expirationTime;
    int state;
		int noResponse;
		bool stateChange;
		bool aviableLin;
public:
    SolarRegulator1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
		void processInfoFrame(uint8_t* frame);
};

#endif