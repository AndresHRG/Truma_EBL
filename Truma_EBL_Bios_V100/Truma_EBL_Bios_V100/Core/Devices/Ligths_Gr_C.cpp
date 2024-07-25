#include "Ligths_Gr_C.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

LigthsGrC::LigthsGrC(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state =0;
}

void LigthsGrC::setOn()
{
    //Pendiente de Implementacion 
}

void LigthsGrC::setOff()
{
    //Pendiente de Implementacion 
}

void LigthsGrC::updateState()
{
    //Pendiente de Implementacion 
}

void LigthsGrC::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int LigthsGrC::getTopicState()
{
    return state;
}