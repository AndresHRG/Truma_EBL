/* *******************************************************************************
 *       @file              ExternalLigths.cpp
 *       @expl              Proof of concept
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
    return;//Pendiente de Implementacion 
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