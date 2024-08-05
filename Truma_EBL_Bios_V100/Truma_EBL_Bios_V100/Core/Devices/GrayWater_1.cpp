/* *******************************************************************************
 *       @file              GrayWater1.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "GrayWater_1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "string.h"

GrayWater1::GrayWater1(short _idTopic): Devices(_idTopic)
{
	expirationTime = 0;
	state = 0xFE;
	levelGW = 0.0;
	counterGW = 0;
	powerTime = 0;
	
	if(variant)
	{
		setOn();
	}
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
	
	expirationTime = GetMilliSec() + 500;
	
	if(variant)
	{
		this->setOn();
		levelGW = (float)ArviGet_AD(BLK7_A);
		levelGW *= 0.14;
	}
	
  if(!variant && (powerTime < GetMilliSec()))
	{
		setOff();
	} 
}

void GrayWater1::topicReceived(uint8_t* topic)
{	
	if(topic[1] != 0)
	{
		if(!variant)//tornillos
		{
			levelGW =0;
			this->setOn();
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
			if(levelGW > 100.0)
				levelGW = 100.0;
			
			if(levelGW <= 0.0)
				levelGW = 0.0;
		}
		
		counterGW ++;//contador de preguntas de solicitud de nivel de agua
			
		if(counterGW > 1)
			state = (int)levelGW;
		
		return;
	}
	
	state = 0xFE;
	counterGW=0;
}

int GrayWater1::getTopicState()
{
    return state;
}