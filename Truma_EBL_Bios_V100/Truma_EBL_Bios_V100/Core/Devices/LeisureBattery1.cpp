#include "LeisureBattery1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "LinMaster.h"
#include "Utils.h"
#include "ErrorManager.h"

extern LinMaster* linMasterInstance;

#define FRAME1 0x22

LeisureBattery1::LeisureBattery1(short _idTopic): Devices(_idTopic), LinClients()
{
    expirationTime = 0;
    state = 0;
		mAmps = 0;
		timeRemaining = 0;
		soc = 0;
		volts = 0;
		this->setIdInfo(linMasterInstance->idCalc(FRAME1));
}

void LeisureBattery1::setOn()
{
}

void LeisureBattery1::setOff()
{
}

void LeisureBattery1::updateState()
{
  if(expirationTime > GetMilliSec())
		return;
	
	expirationTime = GetMilliSec() + 1500;
	
	if(!variant)
	{
		linMasterInstance->sendInfoFrame(linMasterInstance->idCalc(FRAME1));
	}
	else
	{
		mAmps = ArviGet_mA(DRV)/10;
		volts = ArviGet_mV(BAT_2)/100;
		
		if(ArviGet_mV(BAT_2) <= 10500)
			Errors::addError(4,71);
		else if(Errors::errorExists(4,71) && (ArviGet_mV(BAT_2) >= 11500))
			Errors::cleanError(4,71);
	}
}

void LeisureBattery1::topicReceived(uint8_t* topic)
{
}

int LeisureBattery1::getTopicState()
{
    return state;
}

void LeisureBattery1::processInfoFrame(uint8_t* frame)
{
	//estos calculos corresponden a una bateria SuperVolt
	
	volts = frame[0] +(frame[1] << 8);
	volts /= 10;
	
	mAmps = frame[2] +(frame[2] << 8);
	mAmps/= 10;
	
	soc = frame[5] * 2;
	
	if(soc/2 <= 10)
		Errors::addError(4,71);
	else if(Errors::errorExists(4,71) && (soc/2 >= 12))
		Errors::cleanError(4,71);
	
}