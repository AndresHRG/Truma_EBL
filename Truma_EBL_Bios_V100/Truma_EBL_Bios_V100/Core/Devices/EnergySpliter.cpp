#include "EnergySpliter.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

EnergySpliter::EnergySpliter(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void EnergySpliter::setOn()
{
    //Pendiente de Implementacion 
}

void EnergySpliter::setOff()
{
    //Pendiente de Implementacion 
}

void EnergySpliter::updateState()
{
    //Pendiente de Implementacion 
}

void EnergySpliter::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int EnergySpliter::getTopicState()
{
    return state;
}