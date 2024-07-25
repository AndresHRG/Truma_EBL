#include "Ligths_2.h"
#include "InternalLigths.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Ligths2::Ligths2(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Ligths2::setOn()
{
	state = 1;
}

void Ligths2::setOff()
{

}

void Ligths2::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths2::topicReceived(uint8_t* topic)
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
	
#ifdef CAN_ACTIVE
	
	uint8_t data[8];
	
	memset(data, 0, 8);
	data[0] = this->getIdTopic();
	
	if((topic[1] == 3))
	{
		data[1] = state;
		data[3] = 1;//Always Aviable
		canInstance->sendCanMsg(data);
	}
#endif
}

int Ligths2::getTopicState()
{
    return state;
}