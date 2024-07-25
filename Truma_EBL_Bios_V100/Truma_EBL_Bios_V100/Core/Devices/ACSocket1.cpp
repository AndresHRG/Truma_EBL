#include "ACSocket1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

ACSocket1::ACSocket1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void ACSocket1::setOn()
{
    //Pendiente de Implementacion 
}

void ACSocket1::setOff()
{
    //Pendiente de Implementacion 
}

void ACSocket1::updateState()
{
    //Pendiente de Implementacion 
}

void ACSocket1::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int ACSocket1::getTopicState()
{
	return state;
}
