/* *******************************************************************************
 *       @file              EmptyingValve.cpp
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "EmptyingValve.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"

EmptyingValve::EmptyingValve(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
		stateChange = false;
}

void EmptyingValve::setOn()
{
	 Utils::ioDigitalWrite(EMPTY_VALVE_OFF, off);
   Utils::ioDigitalWrite(EMPTY_VALVE_ON, on); 
}

void EmptyingValve::setOff()
{
    Utils::ioDigitalWrite(EMPTY_VALVE_ON, off);// garantizamos que la valvula de aguas grises este apagada
    Utils::ioDigitalWrite(EMPTY_VALVE_OFF, on);
}

void EmptyingValve::updateState()
{
    //Pendiente de Implementacion 
}

void EmptyingValve::topicReceived(uint8_t* topic)
{
    if(topic[1] != ignore)
		{
			stateChange = true;
			if(topic[1] == on)
			{
					state = 1;
					expirationTime = 0;
					setOn();
			}
			else
			{
				state = 3;
				expirationTime = GetMilliSec();
			}
		}
		
		if(expirationTime + 5000 > GetMilliSec())
    {
				state = 3;
        setOff();
    }
    else
		{
			if(state == 3)
				state = 0;//actualizamos estado de valvula para frame de respuesta
			Utils::ioDigitalWrite(EMPTY_VALVE_OFF, off);
		}

}

int EmptyingValve::getTopicState()
{
    return state;
}