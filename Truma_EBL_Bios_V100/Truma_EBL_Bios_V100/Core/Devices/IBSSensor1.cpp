#include "IBSSensor1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

IBSSensor1::IBSSensor1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void IBSSensor1::setOn()
{
    //Pendiente de Implementacion 
}

void IBSSensor1::setOff()
{
    //Pendiente de Implementacion 
}

void IBSSensor1::updateState()
{
    //Pendiente de Implementacion 
}

void IBSSensor1::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int IBSSensor1::getTopicState()
{
    return state;
}