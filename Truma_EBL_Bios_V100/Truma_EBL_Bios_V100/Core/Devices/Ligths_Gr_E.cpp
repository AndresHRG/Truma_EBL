#include "Ligths_Gr_E.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

LigthsGrE::LigthsGrE(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void LigthsGrE::setOn()
{
    //Pendiente de Implementacion 
}

void LigthsGrE::setOff()
{
    //Pendiente de Implementacion 
}

void LigthsGrE::updateState()
{
    //Pendiente de Implementacion 
}

void LigthsGrE::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int LigthsGrE::getTopicState()
{
    return state;
}