#include "Inverter.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"


Inverter::Inverter(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		noResponse = 0;
		stateChange = false;
		aviableLin = true;
}

void Inverter::setOn()
{
  Utils::ioDigitalWrite(INVERTER, on); 
}

void Inverter::setOff()
{
	Utils::ioDigitalWrite(INVERTER, off); 
}

void Inverter::updateState()
{
	
}

void Inverter::topicReceived(uint8_t* topic)
{
	if(topic[1] != ignore)
	{
		if(topic[1] == off)
		{
			setOff();
			state = 0;	
		}
		else
		{
			setOn();
			state = 1;
		}
	}
}

int Inverter::getTopicState()
{
    return state;
}