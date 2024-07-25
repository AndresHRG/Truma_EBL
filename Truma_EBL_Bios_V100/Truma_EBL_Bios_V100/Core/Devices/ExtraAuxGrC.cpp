#include "ExtraAuxGrC.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

ExtraAuxGrC::ExtraAuxGrC(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void ExtraAuxGrC::setOn()
{
    //Pendiente de Implementacion 
}

void ExtraAuxGrC::setOff()
{
    //Pendiente de Implementacion 
}

void ExtraAuxGrC::updateState()
{
    //Pendiente de Implementacion 
}

void ExtraAuxGrC::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int ExtraAuxGrC::getTopicState()
{
    return state;
}