#include "IdentityCheck.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

IdentityCheck::IdentityCheck(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void IdentityCheck::setOn()
{
    //Pendiente de Implementacion 
}

void IdentityCheck::setOff()
{
    //Pendiente de Implementacion 
}

void IdentityCheck::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int IdentityCheck::getTopicState()
{
    return state;
}