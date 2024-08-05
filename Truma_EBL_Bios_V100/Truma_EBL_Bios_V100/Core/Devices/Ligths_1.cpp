/* *******************************************************************************
 *       @file              Ligths_1.cpp
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "Ligths_1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Ligths1::Ligths1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Ligths1::setOn()
{
	Utils::ioDigitalWrite(LIGHT1, 1);
}

void Ligths1::setOff()
{
	Utils::ioDigitalWrite(LIGHT1, 0);
}

void Ligths1::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths1::topicReceived(uint8_t* topic)
{
  if(topic[1] != ignore)
	{
		if(topic[1] == on)
		{
			state = 1;
			setOn();
			
		}
		else
		{
			state = 0;
			setOff();
		}
	}
}

int Ligths1::getTopicState()
{
    return state;
}