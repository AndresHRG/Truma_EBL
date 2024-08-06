/* *******************************************************************************
 *       @file              Fuses.h
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _FUSES_H
#define _FUSES_H

#include "Devices.h"
#include "SystemDevices.h"
#include "Truma_EBL_Bios_V100.h"
#include <vector>

#define FUSE_OK 0
#define FUSE_KO 1

typedef struct
{
	uint8_t fuse;
	uint8_t idFuse;
	
} FUSES;

class Fuses : public Devices, public SystemDevices
{
private:
    uint64_t expirationTime;
    int state;
		std::vector<FUSES> fuses; 
public:
    Fuses(short _idTopic);
		
		void addFuses(FUSES fuse);
    void setOn();
    void setOff();
    void updateState();
    void topicReceived(uint8_t* topic);
    int getTopicState();
};

#endif