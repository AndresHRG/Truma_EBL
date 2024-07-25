#include "AESFridge.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

AESFridge::AESFridge(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void AESFridge::setOn()
{
    //Pendiente de Implementacion 
}

void AESFridge::setOff()
{
    //Pendiente de Implementacion 
}

void AESFridge::updateState()
{
    //Pendiente de Implementacion 
}

void AESFridge::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int AESFridge::getTopicState()
{
    return state;
}