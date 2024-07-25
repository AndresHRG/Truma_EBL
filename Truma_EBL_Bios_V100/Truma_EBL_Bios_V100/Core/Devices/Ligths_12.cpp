#include "Ligths_12.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Ligths12::Ligths12(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void Ligths12::setOn()
{
    //Pendiente de Implementacion 
}

void Ligths12::setOff()
{
    //Pendiente de Implementacion 
}

void Ligths12::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths12::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int Ligths12::getTopicState()
{
    return state;
}