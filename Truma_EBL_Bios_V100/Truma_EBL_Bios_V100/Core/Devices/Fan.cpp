#include "Fan.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

Fan::Fan(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void Fan::setOn()
{
    //Pendiente de Implementacion 
}

void Fan::setOff()
{
    //Pendiente de Implementacion 
}

void Fan::updateState()
{
    //Pendiente de Implementacion 
}

void Fan::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}
int Fan::getTopicState()
{
    return state;
}