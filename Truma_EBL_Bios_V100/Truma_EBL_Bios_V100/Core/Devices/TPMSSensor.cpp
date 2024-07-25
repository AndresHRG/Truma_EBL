#include "TPMSSensor.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

TPMSSensor::TPMSSensor(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void TPMSSensor::setOn()
{
    //Pendiente de Implementacion 
}

void TPMSSensor::setOff()
{
    //Pendiente de Implementacion 
}

void TPMSSensor::updateState()
{
    //Pendiente de Implementacion 
}

void TPMSSensor::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int TPMSSensor::getTopicState()
{
    return state;
}