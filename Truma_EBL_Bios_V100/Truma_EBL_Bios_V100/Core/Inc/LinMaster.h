/* *******************************************************************************
 *       @file              LinMaster.h
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             24-07-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef LIN_MASTER_H
#define LIN_MASTER_H

#include "LinClients.h"
#include <stdint.h>
#include <vector>

#define SIZE_BUFFER 10

class LinMaster
{
private:
    std::vector<LinClients*>clients;
    uint8_t linBuffer[10];
    uint8_t maxReceiveSize;
		uint8_t pReceive;

public:
    LinMaster();
    
    void addClient(LinClients* client);
    void scanBus();
    void composeMsgLin (uint8_t byte);
		void processInfoFrame(uint8_t* frame);
    uint8_t calculateCheckSum(uint8_t* data, short length);
	  uint8_t idCalc(uint8_t idMsg);
    void sendInfoFrame(uint8_t idInfo);
    void sendControlFrame(uint8_t* frame, uint8_t sizeBuffer);
};

#endif