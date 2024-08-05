/* *******************************************************************************
 *       @file              Multimedia.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "Multimedia.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Multimedia::Multimedia(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void Multimedia::setOn()
{
	Utils::ioDigitalWrite(MULTIMEDIA_1, 1);
	Utils::ioDigitalWrite(MULTIMEDIA_2, 1);
	Utils::ioDigitalWrite(MULTIMEDIA_3, 1);
}

void Multimedia::setOff()
{
	Utils::ioDigitalWrite(MULTIMEDIA_1, 0);
	Utils::ioDigitalWrite(MULTIMEDIA_2, 0);
	Utils::ioDigitalWrite(MULTIMEDIA_3, 0);
}

void Multimedia::updateState()
{
    //Pendiente de Implementacion 
}

void Multimedia::topicReceived(uint8_t* topic)
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

int Multimedia::getTopicState()
{
    return state;
}