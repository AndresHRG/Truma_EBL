/* *******************************************************************************
 *       @file              Inverter.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "Inverter.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "LinMaster.h"

#define ID_CONTROL 0x1C

extern LinMaster* linMasterInstance;

Inverter::Inverter(short _idTopic): Devices(_idTopic), LinClients()
{
    expirationTime = 0;
    state = 0;
		noResponse = 0;
		stateChange = false;
		aviableLin = true;
		memset(inverter,0,8);
		inverter[0] = linMasterInstance->idCalc(ID_CONTROL);
}

void Inverter::setOn()
{
  Utils::ioDigitalWrite(INVERTER, on); 
}

void Inverter::setOff()
{
	Utils::ioDigitalWrite(INVERTER, off); 
}

void Inverter::updateState()
{
}

void Inverter::topicReceived(uint8_t* topic)
{
	uint8_t action = on;
	
	if(topic[1] != ignore)
	{
		if(topic[1] == off)
			action = off;

		switch(variant)
		{
			case 1:
			{
				inverter[6] = action;
				inverter[9] = linMasterInstance->calculateCheckSum(inverter, 8);//CRC
				linMasterInstance->sendControlFrame(inverter, SIZE_BUFFER);
				
				break;
			}
			case 2:
			case 4:
			{
				if(action == off)
					setOff();
				else
					setOn();
				
				break;
			}
			case 3:
			{
				inverter[1] = action;
				inverter[2] = (action == off) ? 0x63 : 0x62;//CRC
				linMasterInstance->sendControlFrame(inverter, 3);
				
				break;
			}
			default:
				break;
		
		}
		
		state = action;		
	}
}

int Inverter::getTopicState()
{
    return state;
}

void Inverter::processInfoFrame(uint8_t* frame)
{

}