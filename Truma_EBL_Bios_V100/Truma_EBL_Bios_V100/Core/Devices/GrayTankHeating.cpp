#include "GrayTankHeating.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

GrayTankHeating::GrayTankHeating(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void GrayTankHeating::setOn()
{
    //Pendiente de Implementacion 
}

void GrayTankHeating::setOff()
{
    //Pendiente de Implementacion 
}

void GrayTankHeating::updateState()
{
    //Pendiente de Implementacion 
}

void GrayTankHeating::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int GrayTankHeating::getTopicState()
{
    return state;
}