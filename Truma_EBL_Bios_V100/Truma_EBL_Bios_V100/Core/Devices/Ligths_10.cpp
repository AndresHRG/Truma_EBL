#include "Ligths_10.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"


Ligths10::Ligths10(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Ligths10::setOn()
{
   
}

void Ligths10::setOff()
{
    
}

void Ligths10::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths10::topicReceived(uint8_t* topic)
{
	if(topic[1] != ignore)
	{
		stateChange = true;
		if(topic[1] == on)
			state = 1;
		else
			state = 0;
	}
}

void Ligths10::nigthModeOff()
{
	state = 0;
}

int Ligths10::getTopicState()
{
    return state;
}