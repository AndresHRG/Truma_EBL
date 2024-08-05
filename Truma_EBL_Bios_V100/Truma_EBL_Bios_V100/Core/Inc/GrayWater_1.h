/* *******************************************************************************
 *       @file              GrayWater1.h
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _GRAYWATER1_H
#define _GRAYWATER1_H

#include "Devices.h"
#include "SystemDevices.h"

class GrayWater1 : public Devices, public SystemDevices
{
private:
    unsigned long long expirationTime;
		unsigned long long powerTime;
    int state;
		float levelGW;
		int counterGW;
public:
    GrayWater1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif