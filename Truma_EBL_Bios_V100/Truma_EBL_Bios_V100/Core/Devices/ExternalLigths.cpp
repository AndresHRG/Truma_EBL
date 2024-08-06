/* *******************************************************************************
 *       @file              ExternalLigths.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "ExternalLigths.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

ExternalLigths::ExternalLigths(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
		adcValue = ArviGet_AD(BLK5_4);
}

void ExternalLigths::setOn()
{
	Utils::ioDigitalWrite(EXTERNAL_LIGHTS, on); 
}

void ExternalLigths::setOff()
{
	Utils::ioDigitalWrite(EXTERNAL_LIGHTS, off);
}

void ExternalLigths::updateState()
{
	if(expirationTime > GetMilliSec())
		return;
	
	expirationTime = GetMilliSec() + 60;
	
	if(Utils::compareAnalog(ArviGet_AD(BLK5_4), adcValue, 255))
	{
		adcValue = ArviGet_AD(BLK5_4);
		
		if(state == 0)
		{
			setOn();
			state = 1;
		}
		else
		{
			setOff();
			state = 0;
		}
	}
}

void ExternalLigths::topicReceived(uint8_t* topic)
{
    if(topic[1] != ignore)
		{
			if(topic[1] == off)
			{
				setOff();
				state = 0;	
			}
			else
			{
				setOn();
				state = 1;
			}
		}
		
}

int ExternalLigths::getTopicState()
{
    return state;
}