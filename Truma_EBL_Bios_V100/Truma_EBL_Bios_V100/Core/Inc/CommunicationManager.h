/* *******************************************************************************
 *       @file              CommunicationManager.h
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _COMMUNICATIONMANAGER_H
#define _COMMUNICATIONMANAGER_H

#include "Devices.h"
#include <vector>

class CommunicationManager 
{
private:
	std::vector<Devices*> _devices;

public:
    CommunicationManager();

    void processTopic(uint8_t *topic);
    void notify();
    void addClients(Devices* newDevice);
		int getTopicState(uint8_t idTopic);

};

#endif