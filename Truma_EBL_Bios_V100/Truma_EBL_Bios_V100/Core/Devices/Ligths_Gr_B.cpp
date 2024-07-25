#include "Ligths_Gr_B.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

LigthsGrB::LigthsGrB(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void LigthsGrB::setOn()
{
    //Pendiente de Implementacion 
}

void LigthsGrB::setOff()
{
    //Pendiente de Implementacion 
}

void LigthsGrB::updateState()
{
    //Pendiente de Implementacion 
}

void LigthsGrB::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int LigthsGrB::getTopicState()
{
    return state;
}