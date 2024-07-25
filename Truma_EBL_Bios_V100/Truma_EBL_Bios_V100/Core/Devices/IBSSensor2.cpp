#include "IBSSensor2.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

IBSSensor2::IBSSensor2(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void IBSSensor2::setOn()
{
    //Pendiente de Implementacion 
}

void IBSSensor2::setOff()
{
    //Pendiente de Implementacion 
}

void IBSSensor2::updateState()
{
    //Pendiente de Implementacion 
}

void IBSSensor2::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int IBSSensor2::getTopicState()
{
    return state;
}