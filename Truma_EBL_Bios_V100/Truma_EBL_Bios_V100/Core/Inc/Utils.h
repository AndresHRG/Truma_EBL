#ifndef __UTILS_H
#define __UTILS_H

#include "AddressIO.h"
#include "Truma_EBL_Bios_V100.h"

typedef unsigned char byte;

namespace Utils
{
	int ascci2Integer(char value);
	bool emptyBuffer(char* buffer);
	void initialize2Zero(uint8_t* buffer);
	int ioDigitalWrite(const IOParameters& params, short value);
	int ioDigitalRead(const IOParameters& params);
	int ioPWMWrite(const IOParameters& params, short value);
	byte setBits(unsigned short bitInit, unsigned short bitEnd, short value);
	int round_float_to_nearest(float num);
	void delay_ms(short mSeg);
}

#endif /* __UTILS_H*/