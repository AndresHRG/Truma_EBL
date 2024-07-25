#include "AuxOutPut.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "CanAttender.h"

extern CanAttender* canInstance;

AuxOutPut::AuxOutPut(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void AuxOutPut::setOn()
{
    //Pendiente de Implementacion 
}

void AuxOutPut::setOff()
{
    //Pendiente de Implementacion 
}

void AuxOutPut::updateState()
{
    //Pendiente de Implementacion 
}

void AuxOutPut::topicReceived(uint8_t* topic)
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
		
#ifdef CAN_ACTIVE
	
	uint8_t data[8];
	
	memset(data, 0, 8);
	data[0] = this->getIdTopic();
	
	if((topic[1] == 3) || stateChange)
	{
		stateChange = false;
		data[1] = state;
		data[3] = 1;//Always Aviable
		canInstance->sendCanMsg(data);
	}
#endif 
}

int AuxOutPut::getTopicState()
{
    return state;
}