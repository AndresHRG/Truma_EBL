#include "LinClients.h"

LinClients::LinClients()
{
    _idControl = 0;
    idsInfo.push_back(0);
		sizeInfoFrame = 8;
}
    
void LinClients::setIdControl(uint8_t idControl)
{
    _idControl = idControl;
}
 
void LinClients::setIdInfo(uint8_t idInfo)
{
    idsInfo.push_back(idInfo);
}
 
short LinClients::getIdControl()
{
    return _idControl;
}
 
bool LinClients::verifyIdInfo(uint8_t idInfo)
{
    bool result = false;

    for(int i = 0; i < idsInfo.size(); i++)
    {
       if(idInfo == idsInfo[i])
        result = true;
    }

    return result;
}

void LinClients::processInfoFrame(uint8_t* frame)
{
	//de momento dejamos sin implementacion.
}

void LinClients::setSizeInfoFrame(short size)
{
	sizeInfoFrame  = size;
}

short LinClients::getSizeInfoFrame()
{
	return sizeInfoFrame;
}