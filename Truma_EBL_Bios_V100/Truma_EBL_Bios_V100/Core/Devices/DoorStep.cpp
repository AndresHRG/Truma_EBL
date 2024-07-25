#include "DoorStep.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

DoorStep::DoorStep(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void DoorStep::setOn()
{
  Utils::ioDigitalWrite(DOORSTEP, on);
}

void DoorStep::setOff()
{
  Utils::ioDigitalWrite(DOORSTEP, off);
}

void DoorStep::updateState()
{
    //Pendiente de Implementacion 
}

void DoorStep::topicReceived(uint8_t* topic)
{
  if(topic[1] != ignore)
	{
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

int DoorStep::getTopicState()
{
    return state;
}