#include "Ligths_Gr_D.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

LigthsGrD::LigthsGrD(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void LigthsGrD::setOn()
{
    //Pendiente de Implementacion 
}

void LigthsGrD::setOff()
{
    //Pendiente de Implementacion 
}

void LigthsGrD::updateState()
{
    //Pendiente de Implementacion 
}

void LigthsGrD::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int LigthsGrD::getTopicState()
{
    return state;
}