/* *******************************************************************************
 *       @file              Fuses.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "Fuses.h"
#include "Utils.h"
#include "ErrorManager.h"

#define FUSE_SOS 1

Fuses::Fuses(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		FUSES fuse;
		
		fuse.fuse = FUSE1;
		fuse.idFuse = 1;
		addFuses(fuse);
	
		fuse.fuse = FUSE3;
		fuse.idFuse = 3;
		addFuses(fuse);
		
		fuse.fuse = FUSE4;
		fuse.idFuse = 4;
		addFuses(fuse);
		
		fuse.fuse = FUSE5;
		fuse.idFuse = 5;
		addFuses(fuse);
	
		fuse.fuse = FUSE6;
		fuse.idFuse = 6;
		addFuses(fuse);
	
		fuse.fuse = FUSE7;
		fuse.idFuse = 7;
		addFuses(fuse);
		
		fuse.fuse = FUSE8;
		fuse.idFuse = 8;
		addFuses(fuse);
		
		fuse.fuse = FUSE9;
		fuse.idFuse = 9;
		addFuses(fuse);
		
		fuse.fuse = FUSE10;
		fuse.idFuse = 10;
		addFuses(fuse);
		
		fuse.fuse = FUSE11;
		fuse.idFuse = 11;
		addFuses(fuse);
		
		fuse.fuse = FUSE12;
		fuse.idFuse = 12;
		addFuses(fuse);
		
		fuse.fuse = FUSE13;
		fuse.idFuse = 13;
		addFuses(fuse);
		
		fuse.fuse = FUSE14;
		fuse.idFuse = 14;
		addFuses(fuse);		
}

void Fuses::addFuses(FUSES fuse)
{
	fuses.push_back(fuse);
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
	//static short i = 0; // representa la cantidad de fusibles
	
	if(expirationTime > GetMilliSec())
		return;
	
	expirationTime = GetMilliSec() + 100;
	
	for(const auto& fuse: fuses)
	{
		uint8_t fuseState = ArviGet(fuse.fuse);
		uint8_t state = FUSE_KO;
		
		if(fuse.idFuse == FUSE_SOS)
		{
			state = FUSE_OK;
		}
			
		if(fuseState == state)
			Errors::addError(6,fuse.idFuse);
		else if(Errors::errorExists(6,fuse.idFuse))
			Errors::cleanError(6,fuse.idFuse);
	}

}

void Fuses::topicReceived(uint8_t* topic)
{
}

int Fuses::getTopicState()
{
    return state;
}