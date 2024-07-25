#ifndef CAN_ATTENDER 
#define CAN_ATTENDER

#include "string.h"
#include <stdint.h>
#include "CommunicationManager.h"

#define	ID_MASTER	1

class CanAttender : public CommunicationManager
{
private:
    char* msgArvi;
public:
    CanAttender();

    void sendCanMsg(uint8_t* msg);
    uint8_t* receiveCanMsg();
    void msgIdentifier();
		void alive();
		void traslate2Topic(uint8_t* msg);
};

#endif
