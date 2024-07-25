#include "DPlus_Outputs.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

DPlusOutputs::DPlusOutputs(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void DPlusOutputs::setOn()
{
    //Pendiente de Implementacion 
}

void DPlusOutputs::setOff()
{
    //Pendiente de Implementacion 
}

void DPlusOutputs::updateState()
{
    //Pendiente de Implementacion 
}

void DPlusOutputs::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int DPlusOutputs::getTopicState()
{
    return state;
}