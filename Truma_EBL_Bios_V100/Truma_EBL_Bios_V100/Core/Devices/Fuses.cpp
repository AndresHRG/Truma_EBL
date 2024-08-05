/* *******************************************************************************
 *       @file              Fuses.cpp
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "Fuses.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "ErrorManager.h"

Fuses::Fuses(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void Fuses::setOn()
{
    //Pendiente de Implementacion 
}

void Fuses::setOff()
{
    //Pendiente de Implementacion 
}

void Fuses::updateState()
{
	static short i = 0; // representa la cantidad de fusibles
	
	if(expirationTime > GetMilliSec())
		return;
	
	expirationTime = GetMilliSec() + 80;
	
	//atendemos un fusible a la vez para ir mas rapido a otros procesos
	switch(i)
	{
		case 0:
		{
			byte fuse3 = ArviGet(FUSE3);
			
			if(fuse3 == FUSE_KO)
				Errors::addError(6,3);
			else if(Errors::errorExists(6,3))
				Errors::cleanError(6,3);
			
			break;
		}
		case 1:
		{
			byte fuse4 = ArviGet(FUSE4);
			
			if(fuse4 == FUSE_KO)
				Errors::addError(6,4);
			else if(Errors::errorExists(6,4))
				Errors::cleanError(6,4);
			break;
		}
		case 2:
		{
			byte fuse5 = ArviGet(FUSE5);
			
			if(fuse5 == FUSE_KO)
				Errors::addError(6,5);
			else if(Errors::errorExists(6,5))
				Errors::cleanError(6,5);
			break;
		}
		case 3:
		{
			byte fuse6 = ArviGet(FUSE6);
			
			if(fuse6 == FUSE_KO)
				Errors::addError(6,6);
			else if(Errors::errorExists(6,6))
				Errors::cleanError(6,6);
			break;
		}
		case 4:
		{
			byte fuse7 = ArviGet(FUSE7);
			
			if(fuse7 == FUSE_KO)
				Errors::addError(6,7);
			else if(Errors::errorExists(6,7))
				Errors::cleanError(6,7);
			break;
		}
		case 5:
		{
			byte fuse8 = ArviGet(FUSE8);
			
			if(fuse8 == FUSE_KO)
				Errors::addError(6,8);
			else if(Errors::errorExists(6,8))
				Errors::cleanError(6,8);
			break;
		}
		case 6:
		{
			byte fuse9 = ArviGet(FUSE9);
			
			if(fuse9 == FUSE_KO)
				Errors::addError(6,9);
			else if(Errors::errorExists(6,9))
				Errors::cleanError(6,9);
			break;
		}
		case 7:
		{
			byte fuse10 = ArviGet(FUSE10);
			
			if(fuse10 == FUSE_KO)
				Errors::addError(6,10);
			else if(Errors::errorExists(6,10))
				Errors::cleanError(6,10);
			break;
		}
		case 8:
		{
			byte fuse11 = ArviGet(FUSE11);
			
			if(fuse11 == FUSE_KO)
				Errors::addError(6,11);
			else if(Errors::errorExists(6,11))
				Errors::cleanError(6,11);
			break;
		}
		case 9:
		{
			byte fuse12 = ArviGet(FUSE12);
			
			if(fuse12 == FUSE_KO)
				Errors::addError(6,12);
			else if(Errors::errorExists(6,12))
				Errors::cleanError(6,12);
			break;
		}
		case 10:
		{
			byte fuse13 = ArviGet(FUSE13);
			
			if(fuse13 == FUSE_KO)
				Errors::addError(6,13);
			else if(Errors::errorExists(6,13))
				Errors::cleanError(6,13);
			break;
		}
		case 11:
		{
			byte fuse14 = ArviGet(FUSE14);
			
			if(fuse14 == FUSE_KO)
				Errors::addError(6,14);
			else if(Errors::errorExists(6,14))
				Errors::cleanError(6,14);
			break;
		}
		case 12:
		{
			byte fuse1 = ArviGet(FUSE1);
			
			if(fuse1 == FUSE_OK)
				Errors::addError(6,1);
			else if(Errors::errorExists(6,1))
				Errors::cleanError(6,1);
			break;
		}
		default:
		{
			break;
		}
	}
	i++;
	
	if(i > 12)
		i = 0;
}

void Fuses::topicReceived(uint8_t* topic)
{

}

int Fuses::getTopicState()
{
    return state;
}