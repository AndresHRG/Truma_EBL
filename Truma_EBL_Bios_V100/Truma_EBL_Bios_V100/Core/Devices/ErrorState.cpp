#include "ErrorState.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

ErrorState::ErrorState(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void ErrorState::setOn()
{
    //Pendiente de Implementacion 
}

void ErrorState::setOff()
{
    //Pendiente de Implementacion 
}

void ErrorState::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int ErrorState::getTopicState()
{
    return state;
}