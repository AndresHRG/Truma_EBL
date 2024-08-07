/* *******************************************************************************
 *       @file              SolarRegulator1.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "SolarRegulator1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "LinMaster.h"

extern LinMaster* linMasterInstance;

#define R_LEAB 0x20       // LEAB

SolarRegulator1::SolarRegulator1(short _idTopic): Devices(_idTopic), LinClients()
{
    expirationTime = 0;
    state = 0;
	
		if(variant == 3)
		{
			this->setIdInfo(R_LEAB, 8);
		}
}

void SolarRegulator1::setOn()
{
    //Pendiente de Implementacion 
}

void SolarRegulator1::setOff()
{
    //Pendiente de Implementacion 
}


void SolarRegulator1::updateState()
{
	if(expirationTime > GetMilliSec())
		return;
	
	expirationTime = GetMilliSec() + 1100;
	
	switch(variant)
	{
		case 3:
		{
			linMasterInstance->sendInfoFrame(R_LEAB); 
			break;
		}
		default:
		{
			int mAmps = ArviGet_mA(BLK1_1);
			state = mAmps/10;
			break;
		}
	
	}
}

void SolarRegulator1::topicReceived(uint8_t* topic)
{
}

int SolarRegulator1::getTopicState()
{
    return state;
}

void SolarRegulator1::processInfoFrame(uint8_t* frame)
{
	int mAmps = frame[0] + (frame[1] << 8);
	
	if(mAmps < 400)
		mAmps = 0;
	
	state = mAmps/10;
}