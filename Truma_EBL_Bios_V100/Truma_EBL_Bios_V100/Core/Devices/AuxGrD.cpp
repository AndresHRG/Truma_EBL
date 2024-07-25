#include "AuxGrD.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

AuxGrD::AuxGrD(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void AuxGrD::setOn()
{
    //Pendiente de Implementacion 
}

void AuxGrD::setOff()
{
    //Pendiente de Implementacion 
}

void AuxGrD::updateState()
{
    //Pendiente de Implementacion 
}

void AuxGrD::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int AuxGrD::getTopicState()
{
    return state;
}