#include "Devices.h"

Devices::Devices(short _idTopic)
{
    idTopic = _idTopic;
}

short Devices::getIdTopic()
{
    return idTopic;
}