/* *******************************************************************************
 *       @file              LinClients.h
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
#ifndef LIN_CLIENTS_H
#define LIN_CLIENTS_H

#include <vector>
#include <stdint.h>

typedef struct
{
	uint8_t id;
	uint8_t size;
	
} Frame;

class LinClients
{
private:
    short _idControl;
    std::vector<Frame> frameInfo;
public:
    LinClients();
    
    void setIdControl(uint8_t idControl);
    void setIdInfo(uint8_t idInfo, uint8_t size);

    short getIdControl();
    bool verifyIdInfo(uint8_t idInfo);
		virtual void processInfoFrame(uint8_t* frame);
		void setSizeInfoFrame(short size);
		uint8_t getSizeInfoFrame(uint8_t idInfo);

};

#endif
