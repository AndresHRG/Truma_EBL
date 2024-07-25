#include "Ligths_7.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Ligths7::Ligths7(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void Ligths7::setOn()
{
    Utils::ioDigitalWrite(TEST, on); 
}

void Ligths7::setOff()
{
    Utils::ioDigitalWrite(TEST, off); 
}

void Ligths7::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths7::topicReceived(uint8_t* topic)
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

int Ligths7::getTopicState()
{
    return state;
}