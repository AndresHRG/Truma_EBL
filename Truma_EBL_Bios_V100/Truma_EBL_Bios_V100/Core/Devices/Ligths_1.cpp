#include "Ligths_1.h"
#include "InternalLigths.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "CanAttender.h"


Ligths1::Ligths1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Ligths1::setOn()
{
	Utils::ioDigitalWrite(LIGHT1, 1);
}

void Ligths1::setOff()
{
	Utils::ioDigitalWrite(LIGHT1, 0);
}

void Ligths1::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths1::topicReceived(uint8_t* topic)
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

int Ligths1::getTopicState()
{
    return state;
}