#include "Ligths_8.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Ligths8::Ligths8(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void Ligths8::setOn()
{
    Utils::ioDigitalWrite(TEST, on);
}

void Ligths8::setOff()
{
    Utils::ioDigitalWrite(TEST, off); 
}

void Ligths8::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths8::topicReceived(uint8_t* topic)
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

int Ligths8::getTopicState()
{
    return state;
}