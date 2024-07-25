#include "HomeAlarm1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

HomeAlarm1::HomeAlarm1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void HomeAlarm1::setOn()
{
    //Pendiente de Implementacion 
}

void HomeAlarm1::setOff()
{
    //Pendiente de Implementacion 
}

void HomeAlarm1::updateState()
{
    //Pendiente de Implementacion 
}

void HomeAlarm1::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int HomeAlarm1::getTopicState()
{
    return state;
}