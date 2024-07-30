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
	if(topic[1] != ignore)
	{
		if(topic[1] == off)
		{
			if(!variant)
			{
				if(!variant3)//dometic 
				{
					inverter[6] = 0x00;
					inverter[9] = linMasterInstance->calculateCheckSum(inverter, 8);//CRC
					linMasterInstance->sendControlFrame(inverter, SIZE_BUFFER);
				}
				else// leab
				{
					inverter[1] = 0x00;
					inverter[2] = 0x63;//CRC
					linMasterInstance->sendControlFrame(inverter, 3);
				}
			}
			else
			{
				setOff();
			}
			
			state = 0;	
		}
		else
		{
			if(!variant)
			{	
				if(!variant3)//dometic 
				{
					inverter[6] = 0x01;
					inverter[9] = linMasterInstance->calculateCheckSum(inverter, 8);//CRC
					
					linMasterInstance->sendControlFrame(inverter, SIZE_BUFFER);
				}
				else// leab
				{
					inverter[1] = 0x01;
					inverter[2] = 0x62;//CRC
					linMasterInstance->sendControlFrame(inverter, 3);
				}
			}
			else
			{
				setOn();
			}
			state = 1;
		}
	}
}

int Inverter::getTopicState()
{
    return state;
}
