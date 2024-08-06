/* *******************************************************************************
 *       @file              Ligths_1.h
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _LIGTHS_1_H
#define _LIGTHS_1_H

#include "Devices.h"
#include "SystemDevices.h"

class Ligths1 : public Devices, public SystemDevices
{
private:
    uint64_t expirationTime;
    int state;
		bool stateChange;
		uint16_t adcValue;

public:
    Ligths1(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif