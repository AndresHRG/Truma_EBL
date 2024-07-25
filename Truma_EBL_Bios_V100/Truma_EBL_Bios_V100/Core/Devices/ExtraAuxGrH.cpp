#include "ExtraAuxGrH.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

ExtraAuxGrH::ExtraAuxGrH(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void ExtraAuxGrH::setOn()
{
    //Pendiente de Implementacion 
}

void ExtraAuxGrH::setOff()
{
    //Pendiente de Implementacion 
}

void ExtraAuxGrH::updateState()
{
    //Pendiente de Implementacion 
}

void ExtraAuxGrH::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int ExtraAuxGrH::getTopicState()
{
    return state;
}