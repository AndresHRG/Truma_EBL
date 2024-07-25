#include "GrayWater_1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "string.h"

GrayWater1::GrayWater1(short _idTopic): Devices(_idTopic)
{
	expirationTime = 0;
	state = 0xFE;
	levelGW = 0;
	counterGW = 0;
	powerTime = 0;
}

void GrayWater1::setOn()
{
    Utils::ioDigitalWrite(GWATERON, on);//encendemos sonda para lectura
}

void GrayWater1::setOff()
{
    Utils::ioDigitalWrite(GWATERON, off); //apagamos sonda
}

void GrayWater1::updateState()
{
	if(expirationTime > GetMilliSec())
		return;
	
  if(powerTime < GetMilliSec())
	{
		setOff();
	} 
}

void GrayWater1::topicReceived(uint8_t* topic)
{	
	if(topic[1] != 0)
	{
		levelGW =0;
		
		if(!variant)
		{
			this->setOn();
			expirationTime = GetMilliSec() + 5000;
			
			powerTime = GetMilliSec() + 10000;
			
			if(Utils::ioDigitalRead(GWATER25) > 255)
					levelGW =25;
			if(Utils::ioDigitalRead(GWATER50) > 255)
					levelGW =50;
			if(Utils::ioDigitalRead(GWATER75) > 255)
					levelGW =75;
			if(Utils::ioDigitalRead(GWATER100) > 255)
					levelGW =100;
		}
		else //sensor 0-180
		{
			//pendiente de implementacion
		}
		
		counterGW ++;//contador de preguntas de solicitud de nivel de agua
			
		if(counterGW > 1)
			state = levelGW;
		
		return;
	}
	
	state = 0xFE;
	counterGW=0;
}

int GrayWater1::getTopicState()
{
    return state;
}