#include "FreshWater_1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "string.h"

FreshWater1::FreshWater1(short _idTopic): Devices(_idTopic)
{
	expirationTime = 0;
	state = 0xFE;
	levelFW = 0;
	counterFW = 0;
	powerTime = 0;
}

void FreshWater1::setOn()
{
    Utils::ioDigitalWrite(FWATERON, on);//encendemos sonda para lectura 
}

void FreshWater1::setOff()
{
    Utils::ioDigitalWrite(FWATERON, off);// apagamos sonda
}

void FreshWater1::updateState()
{
	if(expirationTime > GetMilliSec())
		return;
	
  if(powerTime < GetMilliSec())
	{
		setOff();
	}
}

void FreshWater1::topicReceived(uint8_t* topic)
{
  if(topic[1] != 0)
	{
		levelFW =0;
		
		if(!variant)
		{
			this->setOn();
			expirationTime = GetMilliSec() + 5000;
			powerTime = GetMilliSec() + 10000;
			
			if(Utils::ioDigitalRead(FWATER25) > 255)
					levelFW  =25;
			if(Utils::ioDigitalRead(FWATER50) > 255)
					levelFW  =50;
			if(Utils::ioDigitalRead(FWATER75) > 255)
					levelFW  =75;
			if(Utils::ioDigitalRead(FWATER100) > 255)
					levelFW  =100;
		}
		else //sensor 0-180
		{
			//pendiente de implementacion
		}

		counterFW ++;//contador de preguntas de solicitud de nivel de agua
		
		if(counterFW > 1)
			state = levelFW;
		
		return;		
	}
	
	state = 0xFE;
	counterFW=0;
}

int FreshWater1::getTopicState()
{
    return state;
}