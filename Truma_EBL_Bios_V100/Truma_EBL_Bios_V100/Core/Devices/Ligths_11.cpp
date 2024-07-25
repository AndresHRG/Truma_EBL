#include "Ligths_11.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Ligths11::Ligths11(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void Ligths11::setOn()
{
    //Pendiente de Implementacion 
}

void Ligths11::setOff()
{
    //Pendiente de Implementacion 
}

void Ligths11::updateState()
{
    //Pendiente de Implementacion 
}

void Ligths11::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int Ligths11::getTopicState()
{
    return state;
}