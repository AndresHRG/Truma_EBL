#include "FloorHeating.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

FloorHeating::FloorHeating(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void FloorHeating::setOn()
{
}

void FloorHeating::setOff()
{
}

void FloorHeating::updateState()
{
    //No hay que implementar de momento
		return; 
}

void FloorHeating::topicReceived(uint8_t* topic)
{
	if(topic[1] != ignore)
	{		
		stateChange = true;
		if(topic[1] == on)
		{
			state = 1;
			setOn();
		}
		else
		{
			state = 0;
			setOff();
		}
	}	
}

int FloorHeating::getTopicState()
{
    return state;
}