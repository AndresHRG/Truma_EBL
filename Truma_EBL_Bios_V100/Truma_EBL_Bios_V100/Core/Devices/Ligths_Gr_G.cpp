#include "Ligths_Gr_G.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

LigthsGrG::LigthsGrG(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void LigthsGrG::setOn()
{
    //Pendiente de Implementacion 
}

void LigthsGrG::setOff()
{
    //Pendiente de Implementacion 
}

void LigthsGrG::updateState()
{
    //Pendiente de Implementacion 
}

void LigthsGrG::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int LigthsGrG::getTopicState()
{
    return state;
}