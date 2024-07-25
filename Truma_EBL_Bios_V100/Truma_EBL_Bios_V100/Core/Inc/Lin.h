#ifndef LIN_H
#define LIN_H

#include <stdint.h>
#include <vector>

#include "CommunicationManager.h"

#define BYTE_INICIO_LIN 0x55
#define SIZE_BUFFER_LIN 10
#define SLAVE 1
#define MASTER 2

typedef unsigned char byte;

enum linStates {linHeader = 1, messageId, payLoad, crcLoad};

class Lin : public CommunicationManager
{
private:
    byte linBuffer[SIZE_BUFFER_LIN];
		byte linstate;
		byte maxReceiveSize;
		byte pReceive;
		
		bool eState;
		bool vFirmware;
		
		// Buffers info Frames
		byte infoSwitch[SIZE_BUFFER_LIN];
		byte infoWaterMng[SIZE_BUFFER_LIN];
		byte infoVehicleBatt[SIZE_BUFFER_LIN];
		byte infoLeisure1Batt[SIZE_BUFFER_LIN];
		byte infoLeisure2Batt[SIZE_BUFFER_LIN];
		byte infoBatteryMng[SIZE_BUFFER_LIN];

public:
    Lin();

    void sendFrame(unsigned char* frame,short sizeBuffer = SIZE_BUFFER_LIN);
		void composeMsgLin (unsigned char caracter);
		void verifyInfoFrame(unsigned char caracter);
		void traslate2Topic(unsigned char* frame);
		void updateInfoFrames();
		uint8_t calculateCheckSum(unsigned char* data, short length, bool enhancedMode = false);
};

#endif
