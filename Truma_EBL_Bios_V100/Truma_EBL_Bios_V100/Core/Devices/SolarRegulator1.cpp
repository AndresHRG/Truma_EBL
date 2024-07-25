#include "SolarRegulator1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"


SolarRegulator1::SolarRegulator1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void SolarRegulator1::setOn()
{
    //Pendiente de Implementacion 
}

void SolarRegulator1::setOff()
{
    //Pendiente de Implementacion 
}


void SolarRegulator1::updateState()
{
	if(expirationTime > GetMilliSec())
		return;
	
	expirationTime = GetMilliSec() + 1100;
	
	int mAmps = ArviGet_mA(BLK1_1);
	state = mAmps/10;
}

void SolarRegulator1::topicReceived(uint8_t* topic)
{
}

int SolarRegulator1::getTopicState()
{
    return state;
}