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

class LinClients
{
private:
    short _idControl;
    std::vector<uint8_t> idsInfo;
		short sizeInfoFrame;
public:
    LinClients();
    
    void setIdControl(uint8_t idControl);
    void setIdInfo(uint8_t idInfo);

    short getIdControl();
    bool verifyIdInfo(uint8_t idInfo);
		virtual void processInfoFrame(uint8_t* frame);
		void setSizeInfoFrame(short size);
		short getSizeInfoFrame();

};

#endif
