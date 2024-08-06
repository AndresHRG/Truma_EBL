/* *******************************************************************************
 *       @file              LinClients.h
 *       @expl              Truma EBL
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

enum NumberFrames { frame1 = 1, frame2, frame3, frame4, frame5};
	
typedef struct
{
	uint8_t id;
	uint8_t size;
	
} Frame;

class LinClients
{
private:
    uint8_t _idControl;
    std::vector<Frame> frameInfo;

public:
    LinClients();
    
    void setIdControl(uint8_t idControl);
    void setIdInfo(uint8_t idInfo, uint8_t size);

    uint8_t getIdControl();
    bool verifyIdInfo(uint8_t idInfo);
		virtual void processInfoFrame(uint8_t* frame) = 0;
		uint8_t getSizeInfoFrame(uint8_t idInfo);
		uint8_t getNumberFramesInfo();

		//Index frame info
		uint8_t numberFrameInfo;
};

#endif
