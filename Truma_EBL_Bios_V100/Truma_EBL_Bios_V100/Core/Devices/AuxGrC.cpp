#include "AuxGrC.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

AuxGrC::AuxGrC(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void AuxGrC::setOn()
{
    //Pendiente de Implementacion 
}

void AuxGrC::setOff()
{
    //Pendiente de Implementacion 
}

void AuxGrC::updateState()
{
    //Pendiente de Implementacion 
}

void AuxGrC::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int AuxGrC::getTopicState()
{
    return state;
}