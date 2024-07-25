#include "Ligths_Gr_F.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

LigthsGrF::LigthsGrF(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void LigthsGrF::setOn()
{
    //Pendiente de Implementacion 
}

void LigthsGrF::setOff()
{
    //Pendiente de Implementacion 
}

void LigthsGrF::updateState()
{
    //Pendiente de Implementacion 
}

void LigthsGrF::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int LigthsGrF::getTopicState()
{
    return state;
}