#include "Ligths_4.h"
#include "Ligths_10.h"
#include "InternalLigths.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Ligths4::Ligths4(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Ligths4::setOn()
{
	state = 1;
}

void Ligths4::setOff()
{
	state = 0;
}

void Ligths4::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths4::topicReceived(uint8_t* topic)
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

int Ligths4::getTopicState()
{
    return state;
}