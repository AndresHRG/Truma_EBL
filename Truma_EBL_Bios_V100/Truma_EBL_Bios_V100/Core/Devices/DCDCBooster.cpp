#include "DCDCBooster.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

DCDCBooster::DCDCBooster(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void DCDCBooster::setOn()
{
    //Pendiente de Implementacion 
}

void DCDCBooster::setOff()
{
    //Pendiente de Implementacion 
}

void DCDCBooster::updateState()
{
    //Pendiente de Implementacion 
}

void DCDCBooster::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int DCDCBooster::getTopicState()
{
    return state;
}