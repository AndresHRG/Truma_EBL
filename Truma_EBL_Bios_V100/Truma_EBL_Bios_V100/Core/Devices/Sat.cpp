#include "Sat.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Sat::Sat(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void Sat::setOn()
{
    Utils::ioDigitalWrite(TEST, on); 
}

void Sat::setOff()
{
    Utils::ioDigitalWrite(TEST, off);  
}

void Sat::updateState()
{
    //Pendiente de Implementacion 
}

void Sat::topicReceived(uint8_t* topic)
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

int Sat::getTopicState()
{
    return state;
}