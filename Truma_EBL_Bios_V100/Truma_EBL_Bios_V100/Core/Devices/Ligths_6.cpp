#include "Ligths_6.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "CanAttender.h"

extern CanAttender* canInstance;

Ligths6::Ligths6(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Ligths6::setOn()
{
  Utils::ioDigitalWrite(TEST, on); 
}

void Ligths6::setOff()
{
  Utils::ioDigitalWrite(TEST, off); 
}

void Ligths6::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths6::topicReceived(uint8_t* topic)
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

int Ligths6::getTopicState()
{
    return state;
}