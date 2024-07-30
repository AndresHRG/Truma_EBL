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
	Utils::ioDigitalWrite(FLOOR_HEATING_1, 1);
	Utils::ioDigitalWrite(FLOOR_HEATING_2, 1);
	Utils::ioDigitalWrite(FLOOR_HEATING_3, 1);
}

void FloorHeating::setOff()
{
	Utils::ioDigitalWrite(FLOOR_HEATING_1, 0);
	Utils::ioDigitalWrite(FLOOR_HEATING_2, 0);
	Utils::ioDigitalWrite(FLOOR_HEATING_3, 0);
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