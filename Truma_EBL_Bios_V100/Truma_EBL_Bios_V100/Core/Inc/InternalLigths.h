/* *******************************************************************************
 *       @file              InternalLigths.h
 *       @expl              Proof of concept
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
    unsigned long long expirationTime;
    int state;
		bool stateChange;
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