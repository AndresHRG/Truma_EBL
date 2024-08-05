/* *******************************************************************************
 *       @file              DrainValve.cpp
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "DrainValve.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

DrainValve::DrainValve(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void DrainValve::setOn()
{
    //Pendiente de Implementacion 
}

void DrainValve::setOff()
{
    //Pendiente de Implementacion 
}

void DrainValve::updateState()
{
    //Pendiente de Implementacion 
}

void DrainValve::topicReceived(uint8_t* topic)
{
    //Pendiente de Implementacion 
}

int DrainValve::getTopicState()
{
    return state;
}