/* *******************************************************************************
 *       @file              EisExMode.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             08-08-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/

#include "EisExMode.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

EisExMode::EisExMode(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void EisExMode::setOn()
{
	Utils::ioDigitalWrite(BOILER_CTRL, 1);
}

void EisExMode::setOff()
{
	Utils::ioDigitalWrite(BOILER_CTRL, 0);
}

void EisExMode::updateState()
{
}

void EisExMode::topicReceived(uint8_t* topic)
{
	uint8_t iTemp = topic[2];
	uint8_t eTemp = topic[3];
	
	if(topic[1] != ignore)
	{
		if(topic[1] == on)
		{
			state = 1;
			
			if(eTemp  < 5)
			{
				state = 3;
				setOn();
			}
		}
		else
		{
			state = 0;
			setOff();
		}
	}
}

int EisExMode::getTopicState()
{
    return state;
}