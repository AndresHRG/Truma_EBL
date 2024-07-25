#include "Ligths_9.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Ligths9::Ligths9(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void Ligths9::setOn()
{
    Utils::ioDigitalWrite(TEST, on);
}

void Ligths9::setOff()
{
    Utils::ioDigitalWrite(TEST, off); 
}

void Ligths9::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths9::topicReceived(uint8_t* topic)
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

int Ligths9::getTopicState()
{
    return state;
}