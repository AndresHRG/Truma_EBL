/* *******************************************************************************
 *       @file              WaterPump.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "WaterPump.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "string.h"

WaterPump ::WaterPump (short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}
void WaterPump::setOn()
{
		Utils::ioDigitalWrite(FWATERPUMP, on); 
}

void WaterPump::setOff()
{
    Utils::ioDigitalWrite(FWATERPUMP, off);
}

void WaterPump::updateState()
{
}

void WaterPump::topicReceived(uint8_t* topic)
{
  uint8_t data[8];
	
	memset(data, 0, 8);
	data[0] = this->getIdTopic();
	
	if(topic[1] != ignore)
	{
		stateChange = true;
		if(topic[1] == on)
		{
			setOn();
			state = 1;
			
		}
		else if(topic[1] == off)
		{
			state = 0;
			setOff();
		}
	} 
}

int WaterPump::getTopicState()
{
    return state;
}