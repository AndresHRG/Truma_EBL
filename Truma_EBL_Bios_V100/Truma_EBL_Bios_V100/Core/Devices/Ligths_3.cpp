#include "Ligths_3.h"
#include "InternalLigths.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Ligths3::Ligths3(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Ligths3::setOn()
{
	state = 1;
}

void Ligths3::setOff()
{
	
}

void Ligths3::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths3::topicReceived(uint8_t* topic)
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

int Ligths3::getTopicState()
{
    return state;
}