/* *******************************************************************************
 *       @file              Devices.cpp
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "Devices.h"

Devices::Devices(short _idTopic)
{
    idTopic = _idTopic;
}

short Devices::getIdTopic()
{
    return idTopic;
}