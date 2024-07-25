#include "DFuses.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

DFuses::DFuses(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void DFuses::setOn()
{
    //Pendiente de Implementacion 
}

void DFuses::setOff()
{
    //Pendiente de Implementacion 
}

void DFuses::updateState()
{
    //Pendiente de Implementacion 
}

void DFuses::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int DFuses::getTopicState()
{
    return state;
}