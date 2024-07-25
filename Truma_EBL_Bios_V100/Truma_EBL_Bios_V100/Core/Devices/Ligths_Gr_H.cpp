#include "Ligths_Gr_H.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

LigthsGrH::LigthsGrH(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void LigthsGrH::setOn()
{
    //Pendiente de Implementacion 
}

void LigthsGrH::setOff()
{
    //Pendiente de Implementacion 
}

void LigthsGrH::updateState()
{
    //Pendiente de Implementacion 
}

void LigthsGrH::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int LigthsGrH::getTopicState()
{
    return state;
}
