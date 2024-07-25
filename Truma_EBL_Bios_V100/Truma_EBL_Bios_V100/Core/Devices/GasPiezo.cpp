#include "GasPiezo.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

GasPiezo::GasPiezo(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void GasPiezo::setOn()
{
    //Pendiente de Implementacion 
}

void GasPiezo::setOff()
{
    //Pendiente de Implementacion 
}

void GasPiezo::updateState()
{
    //Pendiente de Implementacion 
}

void GasPiezo::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int GasPiezo::getTopicState()
{
    return state;
}