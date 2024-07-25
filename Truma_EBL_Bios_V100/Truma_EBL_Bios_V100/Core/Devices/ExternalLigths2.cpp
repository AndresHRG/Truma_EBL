#include "ExternalLigths2.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

ExternalLigths2::ExternalLigths2(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void ExternalLigths2::setOn()
{
    Utils::ioDigitalWrite(TEST, on);
}

void ExternalLigths2::setOff()
{
    Utils::ioDigitalWrite(TEST, off); 
}

void ExternalLigths2::updateState()
{
    //Pendiente de Implementacion 
}

void ExternalLigths2::topicReceived(uint8_t* topic)
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

int ExternalLigths2::getTopicState()
{
    return state;
}