/* *******************************************************************************
 *       @file              CommunicationManager.cpp
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "CommunicationManager.h"
#include "Enums.h"

CommunicationManager::CommunicationManager()
{
}

void CommunicationManager::processTopic(uint8_t *topic)
{
		for(const auto& device : _devices)
    {
        if(device->getIdTopic() == topic[0])
        {
            device->topicReceived(topic);
        }
    }
}

void CommunicationManager::notify()
{
    //Pendiente de implementacion
}

void CommunicationManager::addClients(Devices* newDevice)
{
    _devices.push_back(newDevice);
}

int CommunicationManager::getTopicState(uint8_t idTopic)
{
	for(const auto& device : _devices)
	{
			if(device->getIdTopic() == idTopic)
			{
					return device->getTopicState();
			}
	}
	
	return _ni;
}