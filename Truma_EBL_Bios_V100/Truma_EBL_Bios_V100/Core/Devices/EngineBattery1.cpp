#include "EngineBattery1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "ErrorManager.h"

EngineBattery1::EngineBattery1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		mAmps = 0;
		volts = 0;
}

void EngineBattery1::setOn()
{
}

void EngineBattery1::setOff()
{
}

void EngineBattery1::updateState()
{
	if(expirationTime > GetMilliSec())
		return;
	
	expirationTime = GetMilliSec() + 1000;
	
	mAmps = 0xFFFE;// valor de corriente no disponible
	volts = ArviGet_mV(BAT_M)/100;
}

void EngineBattery1::topicReceived(uint8_t* topic)
{
}

int EngineBattery1::getTopicState()
{
    return state;
}