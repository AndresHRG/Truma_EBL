#include "DrainValve.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

DrainValve::DrainValve(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void DrainValve::setOn()
{
    //Pendiente de Implementacion 
}

void DrainValve::setOff()
{
    //Pendiente de Implementacion 
}

void DrainValve::updateState()
{
    //Pendiente de Implementacion 
}

void DrainValve::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int DrainValve::getTopicState()
{
    return state;
}