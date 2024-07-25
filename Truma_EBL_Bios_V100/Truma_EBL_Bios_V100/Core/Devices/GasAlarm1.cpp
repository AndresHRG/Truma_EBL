#include "GasAlarm1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

GasAlarm1::GasAlarm1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void GasAlarm1::setOn()
{
    //Pendiente de Implementacion 
}

void GasAlarm1::setOff()
{
    //Pendiente de Implementacion 
}

void GasAlarm1::updateState()
{
    //Pendiente de Implementacion 
}

void GasAlarm1::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int GasAlarm1::getTopicState()
{
    return state;
}