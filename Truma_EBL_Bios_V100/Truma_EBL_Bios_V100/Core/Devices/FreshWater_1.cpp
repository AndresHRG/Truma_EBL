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
	
	if(variant)
	{
		setOn();
	}
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
	
	expirationTime = GetMilliSec() + 510;
	
	if(variant)
	{
		this->setOn();
		levelFW = (float)ArviGet_AD(BLK6_A);
		levelFW *= 0.14;
	}
	
  if(!variant && (powerTime < GetMilliSec()))
	{
		setOff();
	} 
}

void FreshWater1::topicReceived(uint8_t* topic)
{
  if(topic[1] != 0)
	{
		if(!variant)//tornillos
		{
			levelFW =0;
			this->setOn();
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
			if(levelFW > 100.0)
				levelFW = 100.0;
			
			if(levelFW <= 0.0)
				levelFW = 0.0;
		}

		counterFW ++;//contador de preguntas de solicitud de nivel de agua
		
		if(counterFW > 1)
			state = (int)levelFW;
		
		return;		
	}
	
	state = 0xFE;
	counterFW=0;
}

int FreshWater1::getTopicState()
{
    return state;
}