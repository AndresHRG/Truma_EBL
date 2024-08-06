/* *******************************************************************************
 *       @file              InternalLigths.h
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/

#ifndef _INTERNALIGTHS_H
#define _INTERNALIGTHS_H

#include "Devices.h"
#include "SystemDevices.h"

class InternalLigths : public Devices, public SystemDevices
{
private:
    uint64_t expirationTime;
    int state;
		bool stateChange;
		uint16_t adcValue;
public:
    InternalLigths(short _idTopic);

    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
		void modeOff();
    int getTopicState();
};

#endif