#include "Boiler.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "TrumaCombiState.h"
#include "Lin.h"


extern Lin* linInstance;

Boiler::Boiler(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Boiler::setOn()
{
    //Pendiente de Implementacion 
}

void Boiler::setOff()
{
    //Pendiente de Implementacion 
}

void Boiler::updateState()
{
    //Pendiente de Implementacion 
}

void Boiler::topicReceived(uint8_t* topic)
{
}

int Boiler::getTopicState()
{
    return state;
}