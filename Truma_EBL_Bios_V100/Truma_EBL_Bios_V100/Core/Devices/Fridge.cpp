/* *******************************************************************************
 *       @file              Fridge.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "Fridge.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Fridge::Fridge(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Fridge::setOn()
{
  Utils::ioDigitalWrite(FRIDGE_CTRL, on);  
}

void Fridge::setOff()
{
  Utils::ioDigitalWrite(FRIDGE_CTRL, off); 
}

void Fridge::updateState()
{
    //Pendiente de Implementacion 
}

void Fridge::topicReceived(uint8_t* topic)
{
  if(topic[1] != ignore)
	{
		if(topic[1] == on)
		{
			state = 1;
			stateChange = true;
			setOn();
		}
		else
		{
			state = 0;
			stateChange = true;
			setOff();
		}
	}
}

int Fridge::getTopicState()
{
    return state;
}