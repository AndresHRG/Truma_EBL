/* *******************************************************************************
 *       @file              LeisureBattery1.cpp
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "LeisureBattery1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "LinMaster.h"
#include "Utils.h"
#include "ErrorManager.h"

extern LinMaster* linMasterInstance;

#define R_SUPER_VOLT 0x22 // SUPERVOLT
#define R_LEAB_1 0x25       // LEAB
#define R_LEAB_2 0x26       // LEAB

LeisureBattery1::LeisureBattery1(short _idTopic): Devices(_idTopic), LinClients()
{
    expirationTime = 0;
    state = 0;
		mAmps = 0;
		timeRemaining = 0;
		soc = 0;
		volts = 0;
	
		checkVariant();
	
		if(!variant3)
		{
			this->setIdInfo(R_SUPER_VOLT, 8);
		}
		else
		{
			this->setIdInfo(R_LEAB_1, 8);
			this->setIdInfo(R_LEAB_2, 7);
		}
		
}

void LeisureBattery1::setOn()
{
}

void LeisureBattery1::setOff()
{
}

void LeisureBattery1::updateState()
{ 
  if(expirationTime > GetMilliSec())
		return;
	
	expirationTime = GetMilliSec() + 1500;
	
	if(!variant)
	{
		if(!variant3)
		{
			linMasterInstance->sendInfoFrame(R_SUPER_VOLT); 
		}
		else
		{
			switch(this->numberFrameInfo)
			{
				case frame1:
				{
					linMasterInstance->sendInfoFrame(R_LEAB_1);
				}
				case frame2:
				{
					linMasterInstance->sendInfoFrame(R_LEAB_2);
				}
				default:
					break;
			}
		}	
	}
	else
	{
		
		mAmps = ArviGet_mA(DRV)/10;
		volts = ArviGet_mV(BAT_2)/100;
		soc = -1;
		
		if(ArviGet_mV(BAT_2) <= 10500)
			Errors::addError(4,71);
		else if(Errors::errorExists(4,71) && (ArviGet_mV(BAT_2) >= 11500))
			Errors::cleanError(4,71);
	}
}

void LeisureBattery1::topicReceived(uint8_t* topic)
{
}

int LeisureBattery1::getTopicState()
{
   return state;
}

void LeisureBattery1::processInfoFrame(uint8_t* frame)
{
	if(!variant3) // procesamiento de datos para superVolt
	{
		volts = frame[0] +(frame[1] << 8);
		volts /= 10;
		
		mAmps = frame[2] +(frame[3] << 8);
		mAmps /= 10;
		
		soc = frame[5] * 2;
	}
	else // procesamiento de datos para Leab
	{
		switch(this->numberFrameInfo)
		{
			case frame1:
			{
				volts =  frame[0];
				break;
			}
			case frame2:
			{
				soc = frame[0];
			
				mAmps = (frame[1] +(frame[2] << 8));
				mAmps -= 32767;
				mAmps/= 10;
				break;
			}
			default:
				break;
		}
	}
	
	if(soc/2 <= 10)
		Errors::addError(4,71);
	else if(Errors::errorExists(4,71) && (soc/2 >= 12))
		Errors::cleanError(4,71);
	
}