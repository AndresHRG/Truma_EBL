/* *******************************************************************************
 *       @file              EngineBattery1.cpp
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _ENGINEBATTERY1_H
#define _ENGINEBATTERY1_H

#include "Devices.h"
#include "SystemDevices.h"

#define MIN_VOLTS 10500 //mV

class EngineBattery1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
    int state;
public:
    EngineBattery1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();

		int mAmps;
		int volts;
};

#endif