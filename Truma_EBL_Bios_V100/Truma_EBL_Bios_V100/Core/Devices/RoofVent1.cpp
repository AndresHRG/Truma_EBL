#include "RoofVent1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

RoofVent1::RoofVent1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void RoofVent1::setOn()
{
    //Pendiente de Implementacion 
}

void RoofVent1::setOff()
{
    //Pendiente de Implementacion 
}

void RoofVent1::updateState()
{
    //Pendiente de Implementacion 
}

void RoofVent1::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int RoofVent1::getTopicState()
{
    return state;
}