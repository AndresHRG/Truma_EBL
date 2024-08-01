#include "LinClients.h"
#include "LinMaster.h"

extern LinMaster* linMasterInstance;

LinClients::LinClients()
{
    _idControl = 0;
		numberFrameInfo = 1;
}
    
void LinClients::setIdControl(uint8_t idControl)
{
    _idControl = idControl;
}
 
void LinClients::setIdInfo(uint8_t idInfo, uint8_t size)
{
		Frame frame;
	
		frame.id = linMasterInstance->idCalc(idInfo);
		frame.size = size;
		
    frameInfo.push_back(frame);
}
 
uint8_t LinClients::getIdControl()
{
    return _idControl;
}
 
bool LinClients::verifyIdInfo(uint8_t idInfo)
{
    bool result = false;
		
		if(frameInfo.empty())
			return result;
		
    for(int i = 0; i < frameInfo.size(); i++)
    {
       if(idInfo == frameInfo[i].id)
			 {
				 result = true;
				 break;
			 }
    }

    return result;
}

void LinClients::processInfoFrame(uint8_t* frame)
{
	//de momento dejamos sin implementacion.
}

uint8_t LinClients::getSizeInfoFrame(uint8_t idInfo)
{
	for(int i = 0; i < frameInfo.size(); i++)
	{
		 if(idInfo == frameInfo[i].id)
			return frameInfo[i].size;
	}
	
	return 8;// default size
}

uint8_t LinClients::getNumberFrameInfo()
{
	return frameInfo.size();
}