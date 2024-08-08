#include "GasBottle.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

GasBottle::GasBottle(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void GasBottle::setOn()
{
}

void GasBottle::setOff()
{
}

void GasBottle::updateState()
{
    if(expirationTime > GetMilliSec())
        return;

    expirationTime = GetMilliSec() + 10;

    state = 0;

    if(ArviGet_AD(BLK10_2) > 255)
			state = 1;
}

void GasBottle::topicReceived(uint8_t* topic)
{
}

int GasBottle::getTopicState()
{
    return state;
}