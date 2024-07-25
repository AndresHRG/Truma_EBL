#include "MainSwitch.h"
#include "Truma_EBL_Bios_V100.h"
#include "Utils.h"
#include "ErrorManager.h"

bool setTime = false;

MainSwitch::MainSwitch(short _idTopic): Devices(_idTopic)
{
    expirationTime = 0;
    state = 0;
}

void MainSwitch::setOn()
{
  //ArviSet(DRV, 1);
}

void MainSwitch::setOff()
{
  //ArviSet(DRV, 0);
}

void MainSwitch::updateState()
{
	long mAmps = 0;// ArviGet_mA(DRV);
		
		if(mAmps > MAX_CURRENT)
		{
			if(!setTime)
			{
				expirationTime = GetMilliSec();
				setTime = true;
			}
			
			if(expirationTime + 60000 < GetMilliSec())
				Errors::addError(5,70);
			
			if(mAmps > ALARM_CURRENT)
				setOff();
		}
		else if(Errors::errorExists(5,70))
		{
			//setOn();
			Errors::cleanError(5,70);
			setTime = false;
		}
}

void MainSwitch::topicReceived(uint8_t* topic)
{
  if(topic[1] != ignore)
	{
		if(topic[1] == on)
		{
			state = 1;
			setOn();
		}
		else
		{
			state = 0;
			setOff();
		}
	} 
}

int MainSwitch::getTopicState()
{
    return state;
}