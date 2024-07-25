#include "AirConditioner1.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "TrumaCombiState.h"
#include "Lin.h"

extern Lin* linInstance;

AirConditioner1::AirConditioner1(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void AirConditioner1::setOn()
{
    //Pendiente de Implementacion 
}

void AirConditioner1::setOff()
{
    //Pendiente de Implementacion 
}

void AirConditioner1::updateState()
{
    //Pendiente de Implementacion 
}

void AirConditioner1::topicReceived(uint8_t* topic)
{
	
}

int AirConditioner1::getTopicState()
{
    return state;
}