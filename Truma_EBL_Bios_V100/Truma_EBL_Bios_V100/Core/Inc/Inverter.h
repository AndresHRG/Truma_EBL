/* *******************************************************************************
 *       @file              Inverter.h
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _INVERTER_H
#define _INVERTER_H

#include "Devices.h"
#include "SystemDevices.h"
#include "LinClients.h"

class Inverter : public Devices, public SystemDevices, public LinClients
{
private:
    unsigned long long expirationTime;
    int state;
		int noResponse;
		bool stateChange;
		bool aviableLin;
		uint8_t inverter[10];
public:
    Inverter(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif