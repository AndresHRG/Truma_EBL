/* *******************************************************************************
 *       @file              FreshWater_1.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
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
	
	expirationTime = GetMilliSec() + 1110;
	
	if((variant == 2) || (variant == 4))
	{
		this->setOn();
		levelFW = (float)ArviGet_AD(BLK6_A);
		levelFW *= 0.14;
	}
  else if((powerTime < GetMilliSec()))
	{
		setOff();
	} 
}

void FreshWater1::topicReceived(uint8_t* topic)
{
  if(topic[1] != 0)
	{
		switch(variant)
		{
			case 1:
			case 3:
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
				
				break;
			}
			case 2:
			case 4:
			{
				if(levelFW > 100.0)
					levelFW = 100.0;
			
				if(levelFW <= 0.0)
					levelFW = 0.0;
				
				break;
			}
			default:
				break;
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