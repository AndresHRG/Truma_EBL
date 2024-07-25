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