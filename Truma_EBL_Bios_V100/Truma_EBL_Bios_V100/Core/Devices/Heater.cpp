#include "Heater.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "TrumaCombiState.h"
#include "Lin.h"


Heater::Heater(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void Heater::setOn()
{
    //Pendiente de Implementacion 
}

void Heater::setOff()
{
    //Pendiente de Implementacion 
}

void Heater::updateState()
{
    //Pendiente de Implementacion 
}

void Heater::topicReceived(uint8_t* topic)
{
}

int  Heater::getTopicState()
{
    return state;
}