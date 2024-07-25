#include "Ligths_Gr_A.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

LigthsGrA::LigthsGrA(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void LigthsGrA::setOn()
{
    //Pendiente de Implementacion 
}

void LigthsGrA::setOff()
{
    //Pendiente de Implementacion 
}

void LigthsGrA::updateState()
{
    //Pendiente de Implementacion 
}

void LigthsGrA::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int LigthsGrA::getTopicState()
{
    return state;
}