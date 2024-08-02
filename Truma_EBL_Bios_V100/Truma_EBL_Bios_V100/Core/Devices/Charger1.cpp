#include "Charger1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "Lin.h"

#define ID_INFO 0x16 //LEAB

extern Lin* linInstance;

Charger1::Charger1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void Charger1::setOn()
{
    //Pendiente de Implementacion 
}

void Charger1::setOff()
{
    //Pendiente de Implementacion 
}

void Charger1::updateState()
{
	
}

void Charger1::topicReceived(uint8_t* topic)
{
 
}

int Charger1::getTopicState()
{
    return state;
}