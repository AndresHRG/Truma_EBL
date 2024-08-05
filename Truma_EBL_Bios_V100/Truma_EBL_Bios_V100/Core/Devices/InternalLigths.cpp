/* *******************************************************************************
 *       @file              InternalLigths.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "InternalLigths.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

InternalLigths::InternalLigths(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void InternalLigths::setOn()
{
	Utils::ioDigitalWrite(LIGHT2, 1);
	Utils::ioDigitalWrite(LIGHT3, 1);
	Utils::ioDigitalWrite(LIGHT4, 1);
	Utils::ioDigitalWrite(LIGHT5, 1);
	Utils::ioDigitalWrite(LIGHT6, 1);
}

void InternalLigths::setOff()
{	
	Utils::ioDigitalWrite(LIGHT2, 0);
	Utils::ioDigitalWrite(LIGHT3, 0);
	Utils::ioDigitalWrite(LIGHT4, 0);
	Utils::ioDigitalWrite(LIGHT5, 0);
	Utils::ioDigitalWrite(LIGHT6, 0);
}

void InternalLigths::updateState()
{
}

void InternalLigths::topicReceived(uint8_t* topic)
{
    if(topic[1] != ignore)
		{
			
			stateChange = true;
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

void InternalLigths::modeOff()
{
	state = 0;
}
int InternalLigths::getTopicState()
{
    return state;
}