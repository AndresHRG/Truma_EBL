#include "Ligths_5.h"
#include "InternalLigths.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Ligths5::Ligths5(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Ligths5::setOn()
{
	state = 1;
	
}

void Ligths5::setOff()
{

}

void Ligths5::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths5::topicReceived(uint8_t* topic)
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

int Ligths5::getTopicState()
{
    return state;
}